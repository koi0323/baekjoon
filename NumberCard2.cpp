#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	map<int, int> m;
	int	nCount;

	scanf("%d", &nCount);
	for(int i = 0; i < nCount; i++)
	{
		int	tmp;
		scanf("%d", &tmp);
		if (m.find(tmp) == m.end())
			m.insert(make_pair(tmp, 1));
		else
			m[tmp]++;
	}
	int tCount;
	scanf("%d", &tCount);
	for (int i = 0; i < tCount; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		printf("%d", m[tmp]);
		if (i + 1 != tCount)
			printf(" ");
	}
}