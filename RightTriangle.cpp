using namespace std;
#include <iostream>
#include <cmath>
#include <algorithm>

int main(int argc, char **argv)
{
	while (1)
	{
		int a, b, c;
		int sum;
		cin >> a >> b >> c;
		a *= a;
		b *= b;
		c *= c;
		sum = a + b + c;
		if (!a & !b & !c)
			break;
		if (a * b * c != 0)
		{
			if (sum - max(max(a, b), c) == max(max(a, b), c))
				cout << "right" << endl;
			else
				cout << "wrong" << endl;
		}
		else
			cout << "wrong" << endl;
	}

}