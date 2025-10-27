//
// Created by jkil on 25. 10. 27..
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
    int n, r, c;
    cin >> n >> r >> c;
    int i = 0;
    int j = 0;
    while (pow(2, i) < r)
        ++i;
    --i;
    while (pow(2, j) < c)
        ++j;
    --j;

}