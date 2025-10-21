//
// Created by jkil on 25. 10. 21..
//
#include <iostream>
#include <map>

using namespace std;

int main(void) {
    int n;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int tmp;
        map <int, int> m;
        scanf ("%d", &tmp);
        if (tmp == 0) {
            if (m.empty())
                printf("0\n");
            else {
                auto it = m.begin();
                printf("%d\n", m.at(0));
                m.erase (it);
                m.insert(make_pair(tmp, tmp));
            }
        }
        else
            m.insert(make_pair(tmp, tmp));
    }
}
