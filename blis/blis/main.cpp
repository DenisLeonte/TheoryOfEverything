#include <iostream>
#include <fstream>
#define N_MAX 1000000
#define b for(int i = 0; i<=1000000;i++)

using namespace std;

ifstream in("blis.in");
ofstream out("blis.out");

int a[N_MAX];
int k;
int n = 0;

void citire()
{
	in >> k;
	int aux;
	while (in >> aux)
	{
		a[n] = aux;
		n++;
	}
}

int binToDec(int v[],int i, int a)
{
	int val = 0;
	int base = 1;
	for (int j = i; j <= a; j++)
	{
		int last = v[j];
		val += base * last;
		base *= 2;
	}
	return val;
}

int move(int v[N_MAX],int i)
{
	if (i == n)
	{
		return 0;
	}
}

int main()
{

	return 0;
}