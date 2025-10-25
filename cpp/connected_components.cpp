//
// Created by jkil on 25. 10. 24..
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
    int v_count, e_count;
    int result = 0;
    queue<int> q;
    scanf("%d %d", &v_count, &e_count);
    vector<int> visited(v_count + 1, 0);
    vector<vector<int>> v(v_count + 1);
    for (int i = 0; i < e_count; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= v_count; i++) {
        if (!visited[i]) {
            q.push(i);
            visited[i] = 1;
            ++result;
            while (!q.empty()) {
                auto it = q.front();
                q.pop();
                for (auto neighbor : v[it]) {
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = 1;
                    }
                }
            }
        }
    }
    printf("%d\n", result);
}