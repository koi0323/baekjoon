#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
	queue<int> q;
	int	n;
	bool flag = true;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		q.push(i);
	while (q.size() != 1)
	{
		if (flag)
		{
			q.pop();
			flag = !flag;
		}
		else
		{
			int tmp = q.front();
			q.pop();
			q.push(tmp);
			flag = !flag;
		}
	}
	printf("%d", q.front());
}