//
// Created by jkil on 25. 10. 21..
//
#include <iostream>
#include <map>

using namespace std;

int main(void) {
    int n;
    map<int, int> m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp == 0) {
            if (m.empty())
                printf("0\n");
            else {
                printf("%d\n", m.begin()->first);
                if (m.begin()->second != 1)
                    m.begin()->second -= 1;
                else
                    m.erase(m.begin());
            }
        }
        else {
            auto it = m.insert(make_pair(tmp, 1));
            if (!it.second)
                m[tmp]++;
        }
    }
}
