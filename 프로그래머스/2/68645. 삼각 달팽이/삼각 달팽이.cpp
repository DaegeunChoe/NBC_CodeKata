#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    
    // 2차원 배열
    // 빈 공간이 있는 대신, 좌표 계산이 간단해짐
    int* array = new int[n*n];
    for (int x=0; x<n; x++) {
        for (int y=0; y<n; y++) {
            array[y*n + x] = 0;
        }
    }
    
    int direction = 0; // 0:아래로, 1:오른쪽으로, 2:대각선위로
    int x=0;
    int y=0;
    int number = 1;
    while (true) {
        int current = y*n + x;
        if (array[current] != 0) {
            break;
        }
        array[current] = number;
        number += 1;
        if (direction == 0) {
            int next = (y+1)*n + x;
            if (y+1 < n && array[next] == 0) {
                y += 1;
            }
            else {
                direction = 1;
                x += 1;
            }
        }
        else if (direction == 1) {
            int next = y*n + (x+1);
            if (x+1 < n && array[next] == 0) {
                x += 1;
            }
            else {
                direction = 2;
                x -= 1;
                y -= 1;
            }
        }
        else { // direction == 2
            int next = (y-1)*n + (x-1);
            if (x-1 >= 0 && y-1 >= 0 && array[next] == 0) {
                x -= 1;
                y -= 1;
            }
            else {
                direction = 0;
                y += 1;
            }
        }
    }
    
    vector<int> answer;
    for (int y=0; y<n; y++) {
        for (int x=0; x<y+1; x++) {
            answer.push_back(array[y*n + x]);
        }
    }
    delete[] array;
    return answer;
}