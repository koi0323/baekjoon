#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return (a);
}

int lcm(int a, int b)
{
	return (a * b / gcd(a, b));
}

int main(int argc, char **argv)
{
	int a, b;

	cin >> a >> b;
	cout << gcd(a, b) << endl;
	cout << lcm(a, b) << endl;
}