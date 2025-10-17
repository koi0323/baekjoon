#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first != b.first)
		return a.first < b.first;
	else
		return a.second < b.second;
}
int main(void)
{
	int dotCount;

	scanf("%d", &dotCount);
	vector<pair<int, int>> v(dotCount);
	for(int i = 0; i < dotCount; i++)
		scanf("%d %d", &(v[i].first), &(v[i].second));
	sort(v.begin(), v.end(), Compare);
	for(int i = 0; i < dotCount; i++)
		printf("%d %d\n", v[i].first, v[i].second);
}