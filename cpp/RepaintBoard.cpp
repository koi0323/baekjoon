//
// Created by jkil on 25. 10. 18..
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Stamp(vector<vector<char>> v, int m, int n) {
    vector<vector<char>> a(8, vector<char>(8));
    vector<vector<char>> b(8, vector<char>(8));
    int flag = 0;
    int min = 2147483647;
    for (int i = 0 ; i < 8; i++) {
        for (int j = 0 ; j < 8; j++) {
            if (flag == 0) {
                a[i][j] = 'W';
                b[i][j] = 'B';
                if (j != 7)
                    flag = 1;
            }
            else {
                a[i][j] = 'B';
                b[i][j] = 'W';
                if (j != 7)
                    flag = 0;
            }
        }
    }
    for (int i = 0; i <= m - 8; i++) {
        for (int j = 0; j <= n - 8; j++) {
            int minA = 0;
            int minB = 0;
            for (int k = 0; k <= 7; k++) {
                for (int l = 0; l <= 7; l++) {
                    if (a[k][l] != v[i + k][j + l])
                        minA++;
                    if (b[k][l] != v[i + k][j + l])
                        minB++;
                }
            }
            if (minA > minB) {
                if (min > minB)
                    min = minB;
            }
            else {
                if (min > minA)
                    min = minA;
            }
        }
    }
    return (min);
}
int main(void) {
    int m, n;
    scanf("%d %d", &m, &n);
    vector<vector<char>> v(m, vector<char>(n));

    for (int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < n; j++) {
            v[i][j] = tmp[j];
        }
    }
    int result = Stamp(v, m, n);
    printf("%d", result);

}