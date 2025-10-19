#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    int n, k;
    queue<int> q;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        q.push(i + 1);
    }
    printf("<");
    while (!q.empty()) {
        int tmp = k - 1;
        while (tmp > 0) {
            auto it = q.front();
            q.pop();
            q.push(it);
            --tmp;
        }
        printf("%d", q.front());
        q.pop();
        if (!q.empty()) { printf(", ");}
    }
    printf(">");
    return 0;
}