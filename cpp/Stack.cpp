#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	stack<int> s;
	int	count;
	scanf("%d", &count);
	for (int i = 0; i < count; i++)
	{
		string tmp;
		cin >> tmp;
		if (tmp == "push")
		{
			int nTmp;
			scanf("%d", &nTmp);
			s.push(nTmp);
		}
		else if(tmp == "pop")
		{
			if(s.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", s.top());
				s.pop();
			}
		}
		else if (tmp == "size")
			printf("%d\n", s.size());
		else if (tmp == "empty")
			printf("%d\n", s.empty());
		else
		{
			if (s.empty())
				printf("-1\n");
			else
				printf("%d\n", s.top());
		}
	}
}