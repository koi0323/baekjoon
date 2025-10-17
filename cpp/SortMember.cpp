#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

bool compare(tuple<int, int, string> a, tuple<int, int, string> b)
{
	if (get<1>(a) != get<1>(b))
		return get<1>(a) < get<1>(b);
	else
		return get<0>(a) < get<0>(b);
}

int main(void)
{
	int mCount;
	scanf ("%d", &mCount);
	vector<tuple<int, int, string>> v;
	for(int i = 0; i < mCount; i++)
	{
		int age;
		char name[101];
		fill_n(name, 101, 0);
		scanf("%d %s", &age, name);
		v.push_back(make_tuple(i, age, (string)name));
	}
	sort(v.begin(), v.end(), compare);
	for(int i = 0; i < mCount; i++)
		printf("%d %s\n", get<1>(v.at(i)), get<2>(v.at(i)).c_str());

}