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
        fill_n(result[i].begin(), m, 2147483647);
    }
    pair<int, int> start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 2) {
                start.first = i;
                start.second = j;
                q.push(start);
            }
            if (board[i][j] == 0)
                result[i][j] = 0;
        }
    }
    int distance = 0;
    while(!q.empty()) {
        auto q_front = q.front();
        if (q_front.first > 0 && q_front.first < n && q_front.second > 0 && q_front.second < n){
            if (board[q_front.first][q_front.second] != 0 && result[q_front.first][q_front.second] > distance)
                result[q_front.first][q_front.second] == distance;
        }
        q.pop();
        ++distance;
        q.push(make_pair(q_front.first - 1, q_front.second));
        q.push(make_pair(q_front.first + 1, q_front.second));
        q.push(make_pair(q_front.first, q_front.second - 1));
        q.push(make_pair(q_front.first, q_front.second + 1));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}