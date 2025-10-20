//
// Created by jkil on 25. 10. 20..
//
#include <iostream>

using namespace std;

void DP(int arr[], int n){
    if (n < 1)
        return;
    if (n % 3 == 0) {
        if (arr[n / 3] == 0) {
            arr[n / 3] = arr[n] + 1;
            DP(arr, n / 3);
        }
        else {
            if (arr[n / 3] > arr[n] + 1) {
                arr[n / 3] = arr[n] + 1;
                DP(arr, n / 3);
            }
        }
    }
    if (n % 2 == 0) {
        if (arr[n / 2] == 0) {
            arr[n / 2] = arr[n] + 1;
            DP(arr, n / 2);
        }
        else {
            if (arr[n / 2] > arr[n] + 1) {
                arr[n / 2] = arr[n] + 1;
                DP(arr, n / 2);
            }
        }
    }
    if (n - 1 > 0) {
        if (arr[n - 1] == 0) {
            arr[n - 1] = arr[n] + 1;
            DP(arr, n - 1);
        }
        else {
            if (arr[n - 1] > arr[n] + 1) {
                arr[n - 1] = arr[n] + 1;
                DP(arr, n - 1);
            }
        }
    }
}
int main(void) {
    int n;
    scanf("%d", &n);
    int arr[n + 1];
    fill_n(arr, n + 1, 0);
    DP(arr, n);
    printf("%d", arr[1]);
}