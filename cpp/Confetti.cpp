//
// Created by jkil on 25. 10. 22..
//
#include <iostream>
#include <vector>
using namespace std;

int white = 0;
int blue = 0;

void BoardCheck(vector<vector<int>> v, int startRow, int endRow, int startCol, int endCol) {
    int a = v[startRow][startCol];
    for (int i = startRow; i < endRow; i++) {
        for (int j = startCol; j < endCol; j++) {
            if (a != v[i][j]) {
                BoardCheck(v, startRow, (startRow + endRow) / 2, startCol, (startCol + endCol) / 2);
                BoardCheck(v, (startRow + endRow) / 2, endRow, startCol, (startCol + endCol) / 2);
                BoardCheck(v, startRow, (startRow + endRow) / 2, (startCol + endCol) / 2, endCol);
                BoardCheck(v, (startRow + endRow) / 2, endRow, (startCol + endCol) / 2, endCol);
                return ;
            }
        }
    }
    if (a == 0)
        white++;
    if (a == 1)
        blue++;
}

int main(void) {
    int len;
    vector<vector<int>> v;
    cin >> len;
    for (int i = 0; i < len; i++) {
        vector<int> tmp;
        for (int j = 0; j < len; j++) {
            int tmpN;
            scanf("%d", &tmpN);
            tmp.push_back(tmpN);
        }
        v.push_back((tmp));
    }
    BoardCheck(v, 0, len, 0, len);
    printf("%d\n%d", white, blue);
}