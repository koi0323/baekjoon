#include <iostream>
#include <cmath>

using namespace std;

int factorial(int n)
{
	if (n == 1 || n == 0)
		return (1);
	return (n * factorial(n - 1));
}

int main(int argc, char **argv)
{
	int n, k;
	cin >> n >> k;
	cout << factorial(n) / (factorial(k) * factorial(n - k));
}