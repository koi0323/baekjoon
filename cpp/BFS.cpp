//
// Created by jkil on 25. 10. 21..
//

#include <iostream>

using namespace std;

void BackTracking(int **arr, int x, int y, int m, int n) {
    if (x < 0 || y < 0 || x >= m || y >= n) {
        return ;
    }
    if (arr[y][x] == 0)
        return ;
    arr[y][x] = 0;
    BackTracking(arr, x, y - 1, m, n);
    BackTracking(arr, x + 1, y, m, n);
    BackTracking(arr, x - 1, y, m, n);
    BackTracking(arr, x, y + 1, m, n);
}

void BFS(int **arr, int m, int n, int *result) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                (*result)++;
                BackTracking(arr, j, i, m, n);
            }
        }
    }
}

int main(void) {
    int tn;
    scanf ("%d", &tn);
    for (int i = 0; i < tn; i++) {
        int m, n, k;
        int result = 0;
        scanf("%d %d %d", &m, &n, &k);
        int **arr = new int* [n];
        for (int j = 0; j < n; j++) {
            arr[j] = new int[m];
            fill_n(arr[j], m, 0);
        }
        for (int j = 0; j < k; j++) {
            int x, y;
            scanf("%d %d", &x, &y);
            arr[y][x] = 1;
        }
        BFS(arr, m, n, &result);
        printf("%d\n", result);
        for (int j = 0; j < n; j++) {
            delete arr[j];
        }
        delete []arr;
    }
}