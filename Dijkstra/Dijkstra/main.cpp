#include <iostream>
#include <fstream>
#define NMAX 50
#define Inf 10000

using namespace std;

int n, x0;
double C[NMAX][NMAX];
int pre[NMAX], M[NMAX];
double d[NMAX];

void Init();
void Print();
int Bellman_Ford();
void Dijkstra();

int main()
{
	Init();
	int a = Bellman_Ford();
	//Dijkstra();
	Print();
	return 0;
}

void Init()
{
	int i, j, m, x, y;
	double c;
	ifstream in("data.in");
	in >> n >> m >> x0;
	for (i = 1; i <= n; i++)
		for (j = i + 1; j <= n; j++)
			C[i][j] = C[j][i] = Inf;
	for (i = 1; i <= m; i++)
	{
		in >> x >> y >> c;
		C[x][y] = c;
	}
	for (i = 1; i <= n; i++)
	{
		d[i] = C[x0][i];
		pre[i] = x0;
	}
	M[x0] = 1;
	pre[x0] = 0;
	in.close();
}

void Print()
{
	int i, j, lg, dr[NMAX];
	for (i = 1; i <= n; i++)
	{
		if (i != x0)
		{
			cout << "Costul drumului de la " << x0 << " la " << i << " este " << d[i] <<" :";
			dr[0] = i;
			lg = 0;
			while (pre[dr[lg]])
			{
				lg++;
				dr[lg] = pre[dr[lg-1]];
			}
			for (j = lg; j >= 0; j--)
				cout << " " << dr[j];
			cout << endl;
		}
	}
}

void Dijkstra()
{
	int i, VfMin, j;
	double dMin;
	for (j = 1; j < n; j++)
	{
		dMin = Inf;
		for (i = 1; i <= n; i++)
		{
			if (!M[i] && dMin > d[i])
			{
				dMin = d[i];
				VfMin = i;
			}
		}
		M[VfMin] = 1;
		for (i = 1; i <= n; i++)
		{
			if (!M[i] && d[i] > dMin + C[VfMin][i])
			{
				pre[i] = VfMin;
				d[i] = dMin + C[VfMin][i];
			}
		}
	}
}

int Bellman_Ford()
{
	int i, j, k;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			for (k = 1; k <= n; k++)
				if (C[j][k] != Inf && d[k] > d[j] + C[j][k])
				{
					d[k] = d[j] + C[j][k];
					pre[k] = j;
				}
	for (j = 1; j <= n; j++)
		for (k = 1; k <= n; k++)
			if (C[j][k] != Inf && d[k] > d[j] + C[j][k])
				return 0;
	return 1;
}