using namespace std;
#include <iostream>
#include <cmath>

void FindPrime(bool *check, int max)
{
	int sqrtMax = sqrt(max);
	for (int i = 2; i <= sqrtMax; i++)
	{
		if (check[i] == 1)
		{
			for (int j = 2; j * i <= max; j++)
				check[j * i] = 0;
		}
	}
}

int main(int argc, char **argv)
{
	int a;
	cin >> a;
	int num[a];
	int sum = 0;
	int max = 0;
	for (int i = 0; i < a; i++)
	{
		cin >> num[i];
		if (max < num[i])
			max = num[i];
	}
	bool check[max + 1];
	fill_n(check, max + 1, 1);
	check[0] = 0;
	check[1] = 0;
	FindPrime(check, max);
	for (int i = 0; i < a; i++)
	{
		if (check[num[i]] == 1)
			sum++;
	}
	cout << sum;
}
	