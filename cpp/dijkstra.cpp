//
// Created by jkil on 25. 10. 26..
//

#include <iostream>
#include <vector>
//queue를 사용한 bfs로 수정하기
using namespace std;

void dijkstra(vector<vector<int>> &board, vector<vector<int>> &result, int i, int j, int before) {
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
        return ;
    if (board[i][j] == 0)
        return ;
    if (before + 1 > result[i][j])
        return ;
    result[i][j] = before + 1;
    dijkstra(board, result, i - 1, j, before + 1);
    dijkstra(board, result, i + 1, j, before + 1);
    dijkstra(board, result, i, j - 1, before + 1);
    dijkstra(board, result, i, j + 1, before + 1);

}
int main(void) {
    int n, m;
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
            }
            if (board[i][j] == 0)
                result[i][j] = 0;
        }
    }
    result[start.first][start.second] = 0;
    dijkstra(board, result, start.first, start.second, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}