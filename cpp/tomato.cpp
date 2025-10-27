//
// Created by jkil on 25. 10. 28..
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
    int n, m;
    int max_date = 0;
    queue<pair<int, int>> q;

    scanf("%d %d", &m, &n);
    vector<vector<int>> board(n, vector<int>(m, 0));
    vector<vector<int>> result(n, vector<int>(m, 2147483647));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 1) {
                q.push(make_pair(i, j));
                result[i][j] = 0;
            }
            if (board[i][j] == -1)
                result[i][j] = -1;
        }
    }

    while (!q.empty()) {
        int first = q.front().first;
        int second = q.front().second;
        int distance = result[first][second];
        q.pop();
        if (first - 1 >= 0 && board[first - 1][second] != -1 && result[first - 1][second] == 2147483647) {
            q.push(make_pair(first - 1, second));
            result[first - 1][second] = distance + 1;
        }
        if (first + 1 < n && board[first + 1][second] != -1 && result[first + 1][second] == 2147483647) {
            q.push(make_pair(first + 1, second));
            result[first + 1][second] = distance + 1;
        }
        if (second - 1 >= 0 && board[first][second - 1] != -1 && result[first][second - 1] == 2147483647) {
            q.push(make_pair(first, second - 1));
            result[first][second - 1] = distance + 1;
        }
        if (second + 1 < m && board[first][second + 1] != -1 && result[first][second + 1] == 2147483647) {
            q.push(make_pair(first, second + 1));
            result[first][second + 1] = distance + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (result[i][j] == 2147483647) {
                printf("-1");
                return 0;
            }
            if (max_date < result[i][j])
                max_date = result[i][j];
        }
    }
    printf("%d", max_date);
}