//
// Created by jkil on 25. 10. 22..
//
#include <iostream>
#include <vector>
using namespace std;

int white = 0;
int blue = 0;

void BoardCheck(vector<vector<int>> v, int startRaw, int endRaw, int startCol, int endCol) {
    a = v[startRaw][startCol];
    for (int i = startRaw; i < endRaw; i++) {
        for (int j = startCol; j < endCol; j++) {
            if (a != v[i][j]) {
                BoardCheck((v, ))
            }
        }
    }
}

int main(void) {
    int len;
    vector<vector<int>> v;
    cin >> len;
    for (int i = 0; i < len; i++) {
        vector<int> tmp;
        for (int j = 0; j < len; j++) {
            int tmpN;
            cin >> tmpN;
            tmp.push_back(tmpN);
        }
        v.push_back((tmp));
    }

}