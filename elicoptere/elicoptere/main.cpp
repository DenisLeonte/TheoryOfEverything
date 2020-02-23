#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("elicoptere.in");
ofstream out("elicoptere.out");

struct insula
{
	//Cele 3 varfuri
	int x1, y1;
	int x2, y2;
	int x3, y3;
};

int n, k, v;
vector <insula> a;

void read()
{
	in >> v;
	in >> n >> k;
	insula x;
	for (int i = 0; i < n; i++)
	{
		in >> x.x1 >> x.y1 >> x.x2 >> x.y2 >> x.x3 >> x.y3;
		a.push_back(x);
	}
}



int main()
{
	read();
	return 0;
}