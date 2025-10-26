//
// Created by jkil on 25. 10. 25..
//

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
    int start, end;
    scanf("%d %d", &start, &end);
    int arr[200001];
    queue<int> q;
    q.push(start);
    fill_n(arr, 200001, -1);
    arr[start] = 0;
    if (start >= end)
        printf("%d", start - end);
    else {
        while (q.front() != end) {
            int q_front =  q.front();
            q.pop();
            if (q_front <= 100000 && arr[q_front * 2] == -1) {
                arr[q_front * 2] = arr[q_front] + 1;
                q.push(q_front * 2);
            }
            if (q_front > 0 && arr[q_front - 1] == -1) {
                q.push(q_front - 1);
                arr[q_front - 1] = arr[q_front] + 1;
            }
            if (q_front < 200000 && arr[q_front + 1] == -1) {
                q.push(q_front + 1);
                arr[q_front + 1] = arr[q_front] + 1;
            }
        }
        printf("%d", arr[end]);
    }
}