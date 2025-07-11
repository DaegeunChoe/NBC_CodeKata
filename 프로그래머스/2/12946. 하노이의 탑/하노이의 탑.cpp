#include <string>
#include <vector>

using namespace std;

// 재귀함수로 구현하는 하노이의 탑 시뮬레이터
void hanoi(int from, int to, int temp, int n, vector<vector<int>>& answer) {
    if (n == 1) {
        answer.emplace_back(2);
        answer.back()[0] = from;
        answer.back()[1] = to;
    }
    else {
        hanoi(from, temp, to, n-1, answer);
        hanoi(from, to, temp, 1, answer);
        hanoi(temp, to, from, n-1, answer);
    }
}


vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(1, 3, 2, n, answer);
    return answer;
}