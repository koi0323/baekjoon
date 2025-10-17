using namespace std;
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

int	get_time(vector<pair<int, int>> building_time, vector<int> graph[], int target)
{
	queue<int> q;
	vector<int> during_time;

	during_time.assign(building_time.size(), -1);
	for (int i = 1; i < building_time.size(); i++)
	{
		if (building_time[i].second == 0)
		{
			q.push(i);
			during_time[i] = building_time[i].first;
		}
	}
	while (building_time[target].second != 0)
	{
		int i = q.front();
		q.pop();
		while (graph[i].size() != 1)
		{
			building_time[graph[i].back()].second--;
			if (building_time[graph[i].back()].second == 0)
				q.push(graph[i].back());
			int tmp_time = during_time[i] + building_time[graph[i].back()].first;
			if (during_time[graph[i].back()] == -1)
				during_time[graph[i].back()] = tmp_time;
			else if (tmp_time >= during_time[graph[i].back()])
				during_time[graph[i].back()] = tmp_time;
			graph[i].pop_back();
		}
	}
	return (during_time[target]);
}

int main(int argc, char *argv[])
{
	int	testcase_count = 0;
	vector<int> result;

	cin >> testcase_count;
	for(int i = 0; i < testcase_count; i++)
	{
		int building_count = 0;
		int rule_count = 0;
		cin >> building_count >> rule_count;
		vector<pair<int, int>> building_time;
		building_time.emplace_back(0, 0);
		vector<int> graph[building_count + 1];
		int	time;
		for(int j = 0; j < building_count; j++)
		{
			graph[j + 1].push_back(0);
			cin >> time;
			building_time.emplace_back(time, 0);
		}
		for (int j = 0; j < rule_count; j++)
		{
			int from, to;
			cin >> from >> to;
			building_time[to].second++;
			graph[from].push_back(to);
		}
		int target = 0;
		cin >> target;
		result.push_back(get_time(building_time, graph, target));
	}
	for(int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
}