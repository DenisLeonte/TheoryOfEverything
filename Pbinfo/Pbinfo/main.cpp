#include <iostream>

using namespace std;

long long int f(long long int x)
{
	if (x <= 2)
		return 1;
	else
		return f(x - 1) + f(x - 2);
}


int main()
{
	cout << f(50);
	return 0;
}