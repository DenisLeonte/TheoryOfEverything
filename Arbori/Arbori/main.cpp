#include <iostream>
#include <fstream>
#include <vector>
#define NMAX 100

using namespace std;

ifstream in("Text.txt");

int rad;
int n;
int t[NMAX];
int st[NMAX], dr[NMAX];
int val[NMAX];

void read(int currentNode)
{
	int x;
	in >> x;
	st[currentNode] = x;
	if (x != 0)
		read(x);
	int y;
	in >> y;
	dr[currentNode] = y;
	if (y != 0)
		read(y);
}

void rsd(int x)
{
	if (x)
	{
		cout << x << " ";
		rsd(st[x]);
		rsd(dr[x]);
	} 
}

int main()
{
	in >> rad;
	read(rad);
	for (int i = 1; i <= n; i++)
	{
		t[st[i]] = i;
		t[dr[i]] = i;
	}
	rsd(rad);
}