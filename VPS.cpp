#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int nCount;
	vector<string> v;
	scanf("%d", &nCount);
	for(int i = 0; i < nCount; i++)
	{
		int result = 0;
		string tc;
		cin >> tc;
		for (int j = 0; j < tc.length(); j++)
		{
			if (tc[j] == '(')
				result++;
			else if (tc[j] == ')')
				result--;
			if (result < 0)
				break ;
		}
		if (result != 0)
			v.push_back("NO\n");
		else
			v.push_back("YES\n");
	}
	for(int i = 0; i < nCount; i++)
		cout << v[i];
}