//
// Created by jkil on 25. 10. 29..
//

#include <iostream>
#include <vector>

using namespace std;

void print_arr(vector<int> &arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

void backtrack(int n, vector<int> &arr, int m, int current_num) {
    if (arr.size() == m) {
        print_arr(arr);
        return ;
    }
    for (int i = current_num; i <= n; i++) {
        arr.push_back(i);
        backtrack(n, arr, m, i + 1);
        arr.pop_back();
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    vector<int> arr;
    cin >> n >> m;
    backtrack(n, arr, m, 1);
}