#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(void)
{
	int nCount;
	int i = 0;
	map<int, int> m;
	scanf("%d", &nCount);
	for(i = 0; i < nCount; i++)
	{
		pair<int, int> tmp;
		scanf("%d", &(tmp.first));
		tmp.second = tmp.first;
		m.insert(tmp);
	}
	int targetCount;
	scanf("%d", &targetCount);
	for (int j = 0; j < targetCount; j++)
	{
		int key;
		scanf("%d", &key);
		auto it = m.find(key);
		if (it != m.end())
			cout << "1\n";
		else
			cout << "0\n";
	}
}