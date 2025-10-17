using namespace std;
#include <iostream>
#include <cmath>

int main(int argc, char **argv)
{
	int count;
	int t[6];
	int set[2];
	int sum;

	sum = 0;
	cin >> count;
	for (int i = 0; i < 6; i++)
		cin >> t[i];
	cin >> set[0] >> set[1];
	for (int i = 0; i < 6; i++)
	{
		if (t[i])
		{
			sum += t[i] / set[0];
			if (t[i] % set[0] != 0)
				sum++;
		}
	}
	cout << sum << endl;
	cout << count / set[1] << " " << count % set[1];
}