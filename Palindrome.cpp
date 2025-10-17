#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string>

using namespace std;

string CheckPalindrome(int n)
{
	string str;
	str = to_string(n);
	int last = 0;
	int first = str.size() - 1;
	while (first > last)
	{
		if (str.at(first) != str.at(last))
			return ("no\n");
		first--;
		last++;
	}
	return ("yes\n");
}

int main(int argc, char **argv)
{
	int n;
	cin >> n;
	while (n)
	{
		cout << CheckPalindrome(n);
		cin >> n;
	}
}