//
// Created by jkil on 25. 10. 25..
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool CompareValue(pair<int, int> p1, pair<int, int> p2) {
    return p1.first < p2.first;
}

bool CompareIndex(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int main(void) {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> origin;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        origin.emplace_back(tmp, i);
    }
    sort(origin.begin(), origin.end(), CompareValue);
    int a = 0;
    for (int i = 0; i < n; i++) {
        int next = i + 1;
        while (origin[i].first == origin[next].first && next < n){
            next++;
        }
        for (int j = i; j < next; j++)
            origin[j].first = a;
        i = next - 1;
        ++a;
    }
    sort(origin.begin(), origin.end(), CompareIndex);
    for (int i = 0; i < n; i++) {
        printf("%d", origin[i].first);
        if (i + 1 != n)
            printf(" ");
    }
}