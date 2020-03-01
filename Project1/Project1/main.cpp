#include <iostream>
#include <fstream>

using namespace std;

int N;
ifstream in("data.in");

struct Nod
{
	int inf;
	Nod* st, * dr;
} *rad;

void citire()
{
	in >> N;
	int x, y, z;
	Nod* p = new Nod;
	Nod* prim = new Nod;
	prim->inf = NULL;
	prim->st = NULL;
	prim->dr = NULL;
	for (int i = 0; i < N; i++)
	{
		in >> x >> y >> z;
		p->inf = x;
		p->st = NULL;
		p->dr = NULL;
		if (prim == NULL)
		{
			prim = p;
		}
	}
	
	p = prim;
	while (p != NULL)
	{
		Nod *a = p->st;
		Nod *b = p->dr;
		if (a->inf == 1 && b->inf == 2)
		{
			rad = p;
			break;
		}
	}
}

int main()
{
	citire();
	cout << rad->inf;
	return 0;
}