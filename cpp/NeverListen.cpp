//
// Created by jkil on 25. 10. 19..
//
#include <iostream>
#include <unordered_map>
#include <list>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
    int m, n;
    list <string> l;
    scanf("%d %d", &m, &n);
    unordered_map<string, int> a;

    a.reserve(m);
    for (int i = 0; i < m; i++) {
        char tmp[21];
        scanf("%s", tmp);
        string name = tmp;
        a.insert({name, 3});
    }
    for (int i = 0; i < n; i++) {
        char tmp[21];
        scanf("%s", tmp);
        auto it = a.find(tmp);
        if (it != a.end()) {
            l.emplace_back(tmp);
        }
    }
    l.sort();
    printf("%lu\n", l.size());
    for (auto it = l.begin(); it != l.end(); it++) {
        cout << *it << '\n';
    }
}