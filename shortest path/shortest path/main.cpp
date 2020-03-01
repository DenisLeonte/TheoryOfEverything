#include <iostream>
#include <fstream>
#define NMAX 50
#define INF 10000

using namespace std;

int n, x0;
double C[NMAX][NMAX];
int pre[NMAX], M[NMAX];
double d[NMAX];

void Init();
void Print();

int main()
{
	int i, VfMin = 1, j;
	double dMin;
	Init();
	for (j = 1; j < n; j++)
	{
		dMin = INF;
		for (i = 1; i <= n; i++)
		{
			if (!M[i] && dMin > d[i])
			{
				dMin = d[i];
				VfMin = i;
			}
		}
		M[VfMin] = 1; //Generated exception
		for (i = 1; i <= n; i++)
		{
			if (!M[i] && d[i] > dMin + C[VfMin][i])
			{
				pre[i] = VfMin;
				d[i] = dMin + C[VfMin][i];
			}
		}
	}
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
	{
		for (j = 1; j <= n; j++)
		{
			C[i][j] = C[j][i] = INF;
		}
	}
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
		cout << "Shortest path cost from " << x0 << " to " << i << " is " << d[i] << endl;
		cout << "The shortest path is : ";
		dr[0] = i;
		lg = 0;
		while (pre[dr[lg]])
		{
			lg++;
			dr[lg] = pre[dr[lg - 1]];
		}
		for (j = lg; j >= 0; j--)
		{
			cout << dr[j] << " ";
		}
		cout << endl;
	}
}