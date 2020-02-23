#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <cmath>

using namespace std;

class Neuron;

typedef vector<Neuron> Layer;

struct Connection
{
	double weight;
	double deltaWeight;
};

class Neuron 
{
public:
	Neuron(unsigned numOutputs, unsigned myIndex);
	void setOutputVal(double val) { m_outputVal = val; }
	double getOutputVal(void) const { return m_outputVal; }
	void feedForward(const Layer &prevLayer);

private:
	static double randomWeight(void) { return rand() / double(RAND_MAX); }
	static double transferFunction(double x);
	static double transferFunctionDerivative(double x);
	double m_outputVal;
	vector<Connection> m_outputWeights;
	unsigned m_myIndex;
};

double Neuron::transferFunction(double x)
{
	//tanh range [-1.0 ..... 1.0]
	return tanh(x);
}

double Neuron::transferFunctionDerivative(double x)
{
	//tanh derivative
	return 1.0 - x * x;
}

void Neuron::feedForward(const Layer& prevLayer)
{
	double sum = 0.0;
	//Sum the previous layers outputs
	//Include the bias node

	for (unsigned n = 0; n < prevLayer.size(); ++n)
	{
		sum += prevLayer[n].getOutputVal() *
			prevLayer[n].m_outputWeights[m_myIndex].weight;
	}

	m_outputVal = Neuron::transferFunction(sum);
}

Neuron::Neuron(unsigned numOutputs, unsigned myIndex)
{
	for (unsigned c = 0; c < numOutputs; ++c)
	{
		m_outputWeights.push_back(Connection());
		m_outputWeights.back().weight = randomWeight();
	}

	m_myIndex = myIndex;
}


class Net
{
public:
	Net(const vector <unsigned> &topology);
	void feedForward(const vector<double>& inputVals);
	void backProp(const vector<double>& targetVals);
	void getResults(vector<double>& resultVals) const {};
private:
	vector <Layer> m_layers;
	double m_error;
	double m_recentAverageError;
	double m_recentAverageSmoothingFactor;
};
void Net::backProp(const vector<double>& targetVals) 
{
	// Calculate overall error
	Layer& outputLayer = m_layers.back();
	m_error = 0.0;

	for (unsigned n = 0; n < outputLayer.size(); ++n)
	{
		double delta = targetVals[n] - outputLayer[n].getOutputVal();
		m_error += delta * delta;
	}
	m_error /= outputLayer.size() - 1; //Get average error squared
	m_error = sqrt(m_error); //RMS
	
	//Calculate average error
	m_recentAverageError =
		(m_recentAverageError * m_recentAverageSmoothingFactor + m_error) /
		(m_recentAverageSmoothingFactor + 1.0);

	//Calculate output layer gradients
	for (unsigned n = 0; n < outputLayer.size() - 1; ++n)
	{
		outputLayer[n].calcOutputGradients(targetVals[n]);
	}

	//Calculate gradients on hidden layers
	for (unsigned layerNum = m_layers.size() - 2; layerNum > 0; --layerNum)
	{

	}

	//update connection weights
}
void Net::feedForward(const vector<double>& inputVals)
{
	assert(inputVals.size() == m_layers[0].size() - 1);

	//assign the input valuse onto the input neurons
	for (unsigned i = 0; i < inputVals.size(); ++i)
	{
		m_layers[0][i].setOutputVal(inputVals[i]);
	}

	//Forward propagate
	for (unsigned layerNum = 1 ;layerNum <m_layers.size();++layerNum)
		{
		Layer& prevLayer = m_layers[layerNum - 1];
		for (unsigned n = 0; n < m_layers[layerNum].size() -1; ++n)
			{
			m_layers[layerNum][n].feedForward(prevLayer);
			}
		}

}

Net::Net(const vector<unsigned> &topology)
{
	unsigned numLayers = topology.size();
	for (unsigned layerNum = 0; layerNum < numLayers; ++layerNum)
	{
		m_layers.push_back(Layer());
		unsigned numberOutputs = layerNum == topology.size() - 1 ? 0 : topology[layerNum + 1];

		//New layer created filled with neurons

		//Creating bias (auxiliary) neurons
		for (unsigned neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum)
		{
			m_layers.back().push_back(Neuron(numberOutputs,neuronNum));
			cout << "Neuron Created!\n";
		}
	}
}



int main()
{
	vector <unsigned> topology;
	topology.push_back(3);
	topology.push_back(2);
	topology.push_back(1);
	Net myNet(topology);

	vector<double> inputVals;
	myNet.feedForward(inputVals);

	vector<double> targetVals;
	myNet.backProp(targetVals);

	vector<double> resultVals;
	myNet.getResults(resultVals);

	return 0;
}