//
// Created by jkil on 25. 10. 19..
//

#include <iostream>
#include <map>

using namespace std;

int main(void) {
    int nCount;
    map<int, int> m;
    scanf("%d", &nCount);
    for (int i = 0; i < nCount; i++) {
        string a;
        cin >> a;
        if (a == "add") {
            int n;
            scanf ("%d", &n);
            m.insert(make_pair(n, n));
        }
        else if (a == "remove") {
            int n;
            scanf("%d", &n);
            m.erase(n);
        }
        else if (a == "check") {
            int n;
            scanf("%d", &n);
            auto it = m.insert(make_pair(n, n));
            if (it.second) {
                m.erase(n);
                printf("0\n");
            }
            else
                printf("1\n");
        }
        else if (a == "toggle") {
            int n;
            scanf("%d", &n);
            auto it = m.insert(make_pair(n, n));
            if (!it.second) {
                m.erase(n);
            }
        }
        else if (a == "all") {
            m.clear();
            for (int i = 0; i < 20; i++) {
                m.insert(make_pair(i + 1, i + 1));
            }
        }
        else {
            m.clear();
        }
    }
}