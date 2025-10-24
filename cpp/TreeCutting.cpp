//
// Created by jkil on 25. 10. 22..
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long GetLen(vector<int> v, int Height) {
    long long len = 0;
    for (int i = 0; i < v.size(); i++) {
        int tmp = v[i] - Height;
        if (tmp < 0)
            tmp = 0;
        len += tmp;
    }
    return len;
}

int main(void) {
    int n, goal;
    int height = 0;
    scanf("%d %d", &n, &goal);
    vector<int> v;

    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (height < tmp)
            height = tmp;
        v.push_back(tmp);
    }
    int min = 0;
    int max = height;
    long long result = 0;
    while (min <= max) {
        int mid = (min + max) / 2;
        long long len = GetLen(v, mid);
        if (len >= goal) {
            result = mid;
            min = mid + 1;
        }
        else
            max = mid - 1;
    }
    cout << result;
}