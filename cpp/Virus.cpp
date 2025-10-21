//
// Created by jkil on 25. 10. 20..
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int Search(vector<int> *v, int m, int n) {
    queue<int> q;
    int arr[m];
    int result = 0;
    fill_n(arr, m, 0);
    if (v[0].size() == 0)
        return 0;
    for (int i = 0; i < v[0].size(); i++) {
        q.emplace(v[0][i]);
        arr[v[0][i]] = 1;
    }
    arr[0] = 1;
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        for (int i = 0; i < v[it].size(); i++) {
            if (arr[v[it][i]] == 0) {
                q.emplace(v[it][i]);
                arr[v[it][i]] = 1;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if (arr[i] == 1)
            ++result;
    }
    return result - 1;
}

int main(void) {
    int m, n;
    scanf("%d %d", &m, &n);
    vector<int> v[m];
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
    }
    int result = Search(v, m, n);
    printf("%d", result);
}