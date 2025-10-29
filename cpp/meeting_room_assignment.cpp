//
// Created by jkil on 25. 10. 29..
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool Compare(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second != p2.second)
        return p1.second < p2.second;
    else
        return p1.first < p2.first;
}

int main(void) {
    int n;
    vector<pair<int, int>> v;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int first, second;
        scanf("%d %d", &first, &second);
        v.push_back(make_pair(first, second));
    }
    sort(v.begin(), v.end(), Compare);
    int result = 1;
    int start_time = v[0].second;
    for (int i = 1; i < n; i++) {
        if (v[i].first >= start_time) {
            result++;
            start_time = v[i].second;
        }
    }
    printf("%d", result);
}