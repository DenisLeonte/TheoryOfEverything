#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <math.h>

using namespace std;

void sigmoid(vector<int> &x)
{
	for (auto it : x)
	{
		it = 1 / (1 + exp(it));
	}
}

void sigmoidDerivative(vector<int>& x)
{
	for (auto it : x)
	{
		it = it * (1 - it);
	}
}

int main()
{

	srand(time(NULL));

	return 0;
}