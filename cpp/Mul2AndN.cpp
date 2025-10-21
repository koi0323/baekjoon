//
// Created by jkil on 25. 10. 20..
//
#include <iostream>
#include <cmath>

using namespace std;

int DP(int arr[], int n) {
    if (n <= 2)
        return arr[n];
    arr[n] = DP(arr, n - 1) + DP(arr, n - 2);
    return arr[n];
}

int main(void) {
    int n;
    scanf("%d", &n);
    int arr[n + 1];
    fill_n(arr, n + 1, 0);
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    DP(arr, n);
    printf("%d", arr[n]);
}