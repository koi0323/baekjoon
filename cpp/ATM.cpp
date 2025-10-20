//
// Created by jkil on 25. 10. 20..
//
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    int arr[n];
    int result = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        result = result + (arr[i] * (n - i));
    }
    printf("%d", result);
}