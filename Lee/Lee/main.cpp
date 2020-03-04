#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

struct Point
{
	int x;
	int y;
};

struct segment
{
	Point begin;
	Point end;
	double lenght;
};

class triunghi
{
private:

public:
	segment creare(Point a,Point b);
	double ariaCalc(segment a, segment b, segment c);
	//segment ipCalc(segment a, segment b);
	segment a;//cat1
	segment b;//cat2
	segment c;//ip
	double aria;
};

/*segment triunghi::ipCalc(segment a, segment b)
{

}*/

double triunghi::ariaCalc(segment a, segment b, segment c)
{
	return (a.lenght * b.lenght) / 2;
}

segment triunghi::creare(Point a, Point b)
{
	segment aux;
	aux.begin = a;
	aux.end = b;
	aux.lenght = sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
	return aux;
}

int main()
{
	triunghi t1;
	Point a1 = { 10, 15 };
	Point b1 = { 25, 10 };

	t1.a = t1.creare(a1,b1);
	cout << t1.a.lenght;
	return 0;
}