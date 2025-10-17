#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char **argv)
{
	int nCount, target;
	int sim = 0;
	cin >> nCount >> target;
	int arr[nCount];
	for (int i = 0; i < nCount; i++)
		cin >> arr[i];
	for (int i = 0; i < nCount - 2; i++)
	{
		for (int j = i + 1; j < nCount - 1; j++)
		{
			for (int k = j + 1; k < nCount; k++)
			{
				if (arr[i] + arr[j] + arr[k] <= target)
				{
					if (target - sim > target - (arr[i] + arr[j] + arr[k]))
						sim = arr[i] + arr[j] + arr[k];
				}
			}
		}
	}
	cout << sim;
}