#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool Compare(int a, int b)
{
	return a < b;
}
int main(void)
{
	int numCount;
	
	scanf("%d", &numCount);
	int arr[numCount];
	for (int i = 0; i < numCount; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + numCount, Compare);
	for (int i = 0; i < numCount; i++)
		printf("%d\n", arr[i]);
}