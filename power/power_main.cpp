#include <iostream>
using namespace std;

int power(int x, int n);

int main()
{
	int test;
	test = power(5, 3);

	cout << "test: " << test << endl;

	return 0;
}

int power(int x, int n)
{
	if (n > 0)
	{
		return x * power(x, n - 1);
	}
	else
		return 1;		// because any number raised to 0 is 1
}