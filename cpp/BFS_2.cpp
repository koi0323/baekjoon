//
// Created by jkil on 25. 10. 26..
//

#include <iostream>
#include <vector>
#include <queue>
//queue를 사용한 bfs로 수정하기
using namespace std;

int main(void) {
    int n, m;
    queue<pair<int, int>> q;
    scanf("%d %d", &n, &m);
    vector<vector<int>> board(n, vector<int>(m));
    vector<vector<int>> result(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        fill_n(result[i].begin(), m, -1);
    }
    pair<int, int> start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 2) {
                start.first = i;
                start.second = j;
                q.push(start);
                result[i][j] = 0;
            }
            if (board[i][j] == 0)
                result[i][j] = 0;
        }
    }
    while(!q.empty()) {
        auto q_front = q.front();
        int first = q_front.first;
        int second = q_front.second;
        int distance = result[first][second];
        q.pop();
        if (first > 0 && board[first - 1][second] != 0 && result[first - 1][second] == -1) {
            result[first - 1][second] = distance + 1;
            q.push(make_pair(first - 1, second));
        }
        if (first < n - 1 && board[first + 1][second] != 0 && result[first + 1][second] == -1) {
            result[first + 1][second] = distance + 1;
            q.push(make_pair(first + 1, second));
        }
        if (second > 0 && board[first][second - 1] != 0 && result[first][second - 1] == -1) {
            result[first][second - 1] = distance + 1;
            q.push(make_pair(first, second - 1));
        }
        if (second < m - 1 && board[first][second + 1] != 0 && result[first][second + 1] == -1) {
            result[first][second + 1] = distance + 1;
            q.push(make_pair(first, second + 1));
        }

    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}