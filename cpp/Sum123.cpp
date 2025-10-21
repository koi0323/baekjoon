//
// Created by jkil on 25. 10. 20..
//
#include <iostream>
#include <vector>

using namespace std;

int DP(int arr[], int n) {
    if (n <= 3)
        return (arr[n]);
    arr[n] = DP(arr, n-1) + arr[n-2] + arr[n-3];
    return arr[n];
}

int main() {
    int n;
    int max = 0;
    scanf("%d", &n);
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        v.emplace_back(tmp);
        if (max < tmp)
            max = tmp;
    }
    int arr1[max + 1];
    fill_n(arr1, max + 1, 0);
    arr1[1] = 1;
    arr1[2] = 2;
    arr1[3] = 4;
    DP(arr1, max);
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr1[v[i]]);
    }
}