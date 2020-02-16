#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct produs
{
	int nrCrt;
	string name;
	float cost;
	float mkCost;
	int depStock;
	int storeStock;
};

struct nod
{
	produs x;
	nod* urm;
} *prim, * ultim;

void creare()
{
	ifstream in("data.in");
	produs y;
	int a= 1;
	while (in >> y.name >> y.cost >> y.mkCost >> y.depStock >> y.storeStock)
	{
		nod* nou = new nod;	     
		y.nrCrt = a;		     
		a++;				     
		nou->x = y;			     
		nou->urm = NULL;	     
		if (prim == NULL)	     
		{					     
			prim = ultim = nou;
		}
		else
		{
			ultim->urm = nou;
			ultim = nou;
		}
	}
}

void nMatch(string x)
{
	nod* p = prim;
	while (p != NULL)
	{
		if (p->x.name == x)
		{
			cout <<p->x.nrCrt << " " << p->x.name << " " << p->x.cost << " " << p->x.mkCost << " " << p->x.storeStock << " " << p->x.depStock << endl;
		}
		p = p->urm;
	}
}

void ASort()
{
	cout << "Lista alfabetica la produsele :" << endl;
	vector<string> aux;
	nod* p = prim;
	while (p != NULL)
	{
		aux.push_back(p->x.name);
		p = p->urm;
	}
	sort(aux.begin(), aux.end());
	for (auto it : aux)
	{
		nMatch(it);
	}
}

void profit()
{
	cout << "Lista cu profitul fiecarui produs :" << endl;
	nod* p = prim;
	while (p != NULL)
	{
		cout << p->x.nrCrt << " " << p->x.name << " " << p->x.cost - p -> x.mkCost << endl;
		p = p->urm;
	}
}

void unReleased()
{
	cout << "Lista cu produsele nelansate :" << endl;
	nod* p = prim;
	while (p != NULL)
	{
		if (p->x.storeStock == 0 && p->x.depStock == 0)
		{
			cout << p->x.nrCrt << " " << p->x.name << " " << p->x.cost << endl;
		}
		p = p->urm;
	}
}

int ProfitPerProd(nod* x)
{
	return x->x.cost * x->x.storeStock + x->x.mkCost * x->x.depStock;
}

void profitTotal()
{
	cout << "Lista cu profitele totale :"<<endl;
	nod* p = prim;
	while (p != NULL)
	{
		cout << p->x.nrCrt << " " << p->x.name << " " << ProfitPerProd(p) << endl;
		p = p->urm;
	}
}

void profitPeMagazin()
{
	cout << "Lista cu profitele pe magazin :" << endl;
	nod* p = prim;
	while (p != NULL)
	{
		cout << p->x.nrCrt << " " << p->x.name << " " << p->x.cost*p->x.storeStock << endl;
		p = p->urm;
	}
}

int main()
{
	creare();
	ASort();
	cout << endl;
	profit();
	cout << endl;
	unReleased();
	cout << endl;
	profitTotal();
	cout << endl;
	profitPeMagazin();
	cout << endl;
	return 0;
}