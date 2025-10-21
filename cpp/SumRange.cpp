//
// Created by jkil on 25. 10. 20..
//
#include <iostream>

using namespace std;

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n + 1];
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        int tmp;
        scanf("%d", &tmp);
        arr[i] = arr[i - 1] + tmp;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        int result = 0;
        scanf("%d %d", &a, &b);
        result = arr[b] - arr[a - 1];
        printf("%d\n", result);
    }
}