#include <iostream>
#include <fstream>
#include <queue>
#define NMAX 100

using namespace std;

struct pos
{
	int x, y;
};

int v[NMAX][NMAX];
int rows[] = { 0,1,1,0 };
int cols[] = { 1,0,0,1 };
int n, m;
pos start, finish;
queue<pos> q;

void read()
{
	ifstream in("data.in");
	in >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			in >> v[i][j];
	in >> start.x >> start.y >> finish.x >> finish.y;
	in.close();
}

void wrap()
{
	for (int i = 0; i <= n + 1; i++)
		v[i][0] = v[i][m + 1] = -1;
	for (int i = 0; i <= m + 1; i++)
		v[0][i] = v[n + 1][i] = -1;
}

void lee()
{
	q.push(start);

	v[start.x][start.y] = 1;

	while (!q.empty())
	{
		pos Pos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			pos ngh;
			ngh.x = Pos.x + rows[i];
			ngh.y = Pos.y + cols[i];
			if (!v[ngh.x][ngh.y])
			{
				v[ngh.x][ngh.y] = v[Pos.x][Pos.y] + 1;
				q.push(ngh);
			}
		}
	}
}

int main()
{
	read();
	wrap();
	return 0;
}