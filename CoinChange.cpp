#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int min(int a, int b)
{
	if (a == -1 && b == -1)
		return (-1);
	if (a == -1)
		return (b);
	if (b == -1)
		return (a);
	return (a > b ? b : a);
}

int minNum(int *value, int *coins, int target, int count)
{
	int min = 2147483647;
	for (int i = 0; i < count; i++)
	{
	}
}

int GetNumber(int *value, int *coins, int target, int count)
{
	int min = 2147483647;
	for (int i = 0; i < count; i++)
	{
		int tmp = -1;
		if (target - coins[i] >= 0)
		{
			value[target - coins[i]] = GetSolution(value, coins, target - coins[i], count);
			if (value[target - coins[i]] != -1)
				tmp = value[target-coins[i]] + 1;
		}
		if (min > tmp)
			min = tmp;
	}
	return min;
}

int GetSolution(int *value, int *coins, int target, int count)
{
	if (target < 0)
		return (-1);
	value[target] = GetNumber(value, coins, target, count);
}

int main(int argc, char *argv[])
{
	int count;
	int target;
	int *value;
	int *coins;

	cin >> count >> target;
	coins = new int[count];
	value = new int[target + 1];
	value[0] = 0;
	for(int i = 1; i < target + 1; i++)
		value[i] = -1;
	for (int i = 0; i < count; i++)
	{
		cin >> coins[i];
		value[coins[i]] = 1;
	}
	sort(coins, coins + count);
	int j = coins[0];
	while (coins[0] + j < coins[1])
	{
		value[coins[0] + j] = value[j] + 1;
		j += coins[0];
	}
	cout << GetSolution(value, coins, target, count);
}