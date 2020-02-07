#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define NMAX 500

using namespace std;
int n, m;
int a[NMAX][NMAX];

void type1(string filename)
{
	ifstream in(filename.c_str());
	in >> n;
	int x;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			in >> x;
			a[i][j] = x;
		}
	}
	in.close();
}

void type2(string filename)
{
	ifstream in(filename.c_str());
	in >> n >> m;
	int x, y;
	for (int i = 0; i < m; i++)
	{
		in >> x >> y;
		a[x][y] = 1;
	}
	in.close();
}

void read(string filename, string typeof)
{
	if (typeof.compare("adiacenta") == 0)
		type1(filename);
	else if (typeof.compare("muchii") == 0)
		type2(filename);
}

void print()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout << endl;
	}
}

int gradintern(int x)
{
	int k = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[x][i] == 1)
			k++;
	}
	return k;
}

int gradextern(int x)
{
	int k = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i][x] == 1)
			k++;
	}
	return k;
}


int main()
{
	read("mat_lat.txt", "muchii");
	print();
	cout << gradextern(4);
	return 0;
}