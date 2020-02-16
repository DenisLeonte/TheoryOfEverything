#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("summax.in");
ofstream out("summax.out");

int n;//Numar de linii
vector <int> a[2000];
int k = 0;
int Max;

int move(int i, int j)
{
	if (i == n-1)
		return a[i][j];
	else
	{
		int s1 = move(i + 1, j);
		int s2 = move(i + 1, j + 1);
		if (s1 == Max)
			k++;
		if (s2 == Max)
			k++;
		if (s1 >= s2)
			return s1+a[i][j];
		else
			return s2+a[i][j];
	}
}

int main()
{	
	int v, st, dr;
	in >> v >> n >> st >> dr;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			int aux;
			in >> aux;
			a[i].push_back(aux);
		}
	}
	Max = move(0, 0);
	k = 0;
	int a = move(0, 0);
	cout << k;
	return 0;
}