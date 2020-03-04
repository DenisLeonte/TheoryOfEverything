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
	double slope;
};

class patrat
{
private:
public:

};

class triunghi
{
private:
	double s;//half perimeter
public:
	segment creare(Point a,Point b);
	double ariaCalc(segment a, segment b, segment c);
	segment ipCalc(segment a, segment b);
	bool perpendicular(segment a, segment b);
	double perimetruCalc(segment a, segment b, segment c);
	segment a;//lat1
	segment b;//lat2
	segment c;//lat3
	double aria;
	double perimetru;
};


double triunghi::perimetruCalc(segment a, segment b, segment c)
{
	return a.lenght + b.lenght + c.lenght;
}

bool triunghi::perpendicular(segment a, segment b)
{
	double x;
	if (a.slope == 0)
		x = 0;
	else
		x = -(1 / a.slope);
	if (x == b.slope)
		return true;
	return false;
}

segment triunghi::ipCalc(segment a, segment b)
{
	if (perpendicular(a, b))
		c.lenght = sqrt(pow(a.lenght, 2) + pow(b.lenght, 2));
	return c;
}

double triunghi::ariaCalc(segment a, segment b, segment c)
{
	s = (a.lenght + b.lenght + c.lenght) / 2;
	return sqrt(s * (s - a.lenght) * (s - b.lenght) * (s - c.lenght));
}

segment triunghi::creare(Point a, Point b)
{
	segment aux;
	aux.begin = a;
	aux.end = b;
	aux.lenght = sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
	if ((b.x - a.x) == 0 || (b.y - a.y) == 0)
		aux.slope = 0;
	else
		aux.slope = (b.y - a.y) / (b.x - a.x);

	return aux;
}

int main()
{
	triunghi T;
	Point A = { 5, 5 };
	Point B = { 15, 5 };
	Point C = { 5, 20 };
	
	T.a = T.creare(A, B);
	T.b = T.creare(A, C);
	
	T.c = T.ipCalc(T.a, T.b);

	cout << T.c.lenght<<endl;
	return 0;
}