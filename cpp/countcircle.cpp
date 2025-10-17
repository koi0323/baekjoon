using namespace std;
#include <iostream>
#include <cmath>
#include <vector>

void DFS(vector<vector<int>> matrix, vector<int> *check, int x, int enemy_count)
{
	if (x >= enemy_count)
		return ;
	for (int i = 0; i < enemy_count; i++)
	{
		if (x != i && (*check)[i] == 0)
		{
			float distance = pow(matrix[0][x] - matrix[0][i], 2) + pow(matrix[1][x] - matrix[1][i], 2);
			if (distance <= pow(matrix[2][x] + matrix[2][i], 2))
			{
				(*check)[i] = 1;
				DFS(matrix, check, i, enemy_count);
			}
		}
	}
	return ;
}


int get_group(vector<vector<int>> matrix, int enemy_count)
{
	vector<int> check(enemy_count);
	int	group_count = 0;
	for (int i = 0; i < enemy_count; i++)
	{
		if (check[i] == 0)
		{
			group_count++;
			DFS(matrix, &check, i, enemy_count);
		}
	}
	return group_count;
}

int main (int argc, char *argv[])
{
	int	test_case = 0;
	int	enemy_count = 0;
	vector<int> group;
	cin >> test_case;
	for(int i = 0; i < test_case; i++)
	{
		cin >> enemy_count;
		vector<vector<int>> matrix(3, vector<int>(enemy_count));
		for (int j = 0; j < enemy_count; j++)
		{
			cin >> matrix[0][j] >> matrix[1][j] >> matrix[2][j];
		}
		group.push_back(get_group(matrix, enemy_count));
		matrix.clear();
	}
	for (int i = 0; i < group.size(); i++)
	{
		cout << group[i] << endl;
	}
	return (0);
}
