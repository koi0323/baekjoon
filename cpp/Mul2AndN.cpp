//
// Created by jkil on 25. 10. 20..
//
#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);
    int arr[n + 1];
    fill_n(arr, n + 1, 0);
    arr[0] = 1;
    arr[1] = 1;
    if (n >= 2) {
        for (int i = 2; i < n + 1; i++)
            arr[i] = ((arr[i - 1]  % 10007) + (arr[i - 2]  % 10007)) % 10007;
    }
    printf("%d", arr[n]);
}