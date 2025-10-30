//
// Created by jkil on 25. 10. 30..
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_arr(vector<int> &arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

void backtrack(int n, vector<int> &arr, int m, vector<pair<int, int>> &num) {
    if (arr.size() == m) {
        print_arr(arr);
        return ;
    }
    for (int i = 0; i < n; i++) {
        if (num[i].second == 0)
            continue ;
        arr.push_back(num[i].first);
        num[i].second = 0;
        backtrack(n, arr, m, num);
        arr.pop_back();
        num[i].second = 1;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, length;
    cin >> n >> length;
    vector<int> arr;
    vector<pair<int, int>> num;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        num.emplace_back(tmp, 1);
    }
    sort(num.begin(), num.end());
    backtrack(n, arr, length, num);
}