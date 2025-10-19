//
// Created by jkil on 25. 10. 19..
//

#include <iostream>
#include <map>

using namespace std;

int Cmp(char *a, char *b) {
    int i = 0;
    while (a[i] != 0 && b[i] != 0) {
        if (a[i] != b[i])
            return (0);
        ++i;
    }
    if (a[i] != b[i])
        return (0);
    else
        return (1);
}
int main(void) {
    int nCount;
    bool arr[21] = {false};
    scanf("%d", &nCount);
    for (int i = 0; i < nCount; i++) {
        char tmp[7] = {0,};
        scanf("%s", tmp);
        if (Cmp(tmp, "add")) {
            int n;
            scanf ("%d", &n);
            arr[n] = true;
        }
        else if (Cmp(tmp, "remove")) {
            int n;
            scanf("%d", &n);
            arr[n] = false;
        }
        else if (Cmp(tmp, "check")) {
            int n;
            scanf("%d", &n);
            arr[n] ? printf("1\n") : printf("0\n");
        }
        else if (Cmp(tmp, "toggle")) {
            int n;
            scanf("%d", &n);
            arr[n] = !arr[n];
        }
        else if (Cmp(tmp, "all")) {
            for (int j = 0; j < 21; j++) {
                arr[j] = true;
            }
        }
        else {
            for (int j = 0; j < 21; j++) {
                arr[j] = false;
            }
        }
    }
}