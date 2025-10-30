//
// Created by jkil on 25. 10. 27..
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
    int n, r, c;
    int result = 0;
    cin >> n >> r >> c;

    pair<int, int> med;
    while (n > 0) {
        med = make_pair(pow(2, n) / 2, pow(2, n) / 2);
        if (med.first <= r) {
            r -= pow(2, n - 1);
            if (med.second <= c) {
                result += pow(pow(2, n - 1), 2) * 3;
                c -= pow(2, n - 1);
            }
            else
                result += pow(pow(2, n - 1), 2) * 2;
        }
        else {
            if (med.second <= c){
                result += pow(pow(2, n - 1), 2) * 1;
                c = c - pow(2, n - 1);
            }
            else
                result += pow(pow(2, n - 1), 2) * 0;
        }
        --n;
    }
    printf("%d", result);
}