#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool Compare(string a, string b)
{
	if (a.length() != b.length())
		return a.length() < b.length();
	else
		return a < b;
}

int main(int argc, char **argv)
{
	int nCount;
	string before = "";
	cin >> nCount;
	string word[20001];
	fill_n(word, 20001, before);
	for(int i = 0; i < nCount; i++)
		cin >> word[i];
	sort(word, word + nCount, Compare);
	for (int i = 0; i < nCount; i++)
	{
		if (word[i] != before)
		{
			cout << word[i] << endl;
			before = word[i];
		}
	}
}