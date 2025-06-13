#include <string>
#include <vector>

#include <iostream>

using namespace std;

// 전선 하나만 끊으면 되므로, 모든 경우를 탐색하면 됨

// 그래프 서치 (트리인건 아는데, 루트가 어디인지 모르기 때문에, 그래프 서치를 해야 함)
void search(int n, int start, vector<vector<bool>>& wire_matrix, vector<int>& group_num) {
    vector<bool> visited(n, false);
    vector<int> queue;
    queue.push_back(start);
    
    while (queue.size() > 0) {
        
        int current = queue.back();
        queue.pop_back();
        
        for (int to=0; to<n; to++) {
            if (wire_matrix[current][to] == true && visited[to] == false) {
                visited[to] = true;
                group_num[to] = group_num[current];
                queue.push_back(to);
            }
        }
    }
}

int function(int n, vector<vector<bool>>& wire_matrix) {
    vector<int> group_num(n, 2);
    
    // 0번 송전탑을 1번 그룹으로 체크하고, 1번 그룹과 연결된 모든 송전탑을 찾는다.
    group_num[0] = 1;
    search(n, 0, wire_matrix, group_num);
    
    // 이제 모든 송전탑은 1번 그룹 아니면 2번 그룹임. 
    // 개수의 차이를 구하면 된다.
    int group1_num = 0;
    int group2_num = 0;
    for (int i=0; i<n; i++) {
        if (group_num[i] == 1)group1_num++;
        else group2_num++;
        cout << group_num[i];
    }
    cout << endl << "---" << endl;
    if (group1_num > group2_num) return group1_num - group2_num;
    else return group2_num - group1_num;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    
    // 연결 행렬 만들기
    vector<vector<bool>> wire_matrix;
    for (int i=0; i<n; i++) {
        wire_matrix.emplace_back(n, false);
    }
    for (vector<int>& wire : wires) {
        int v1 = wire[0] - 1;
        int v2 = wire[1] - 1;
        wire_matrix[v1][v2] = true;
        wire_matrix[v2][v1] = true;
    }
    
    for (vector<int>& wire : wires) {
        int v1 = wire[0] - 1;
        int v2 = wire[1] - 1;
        
        // 전력망 끊기
        cout << "cut: " << wire[0] << ", " << wire[1] << endl;
        wire_matrix[v1][v2] = false;
        wire_matrix[v2][v1] = false;
        
        // 시뮬레이션 하기
        int result = function(n, wire_matrix);
        
        // 최소값 구하기
        if (answer == -1) answer = result;
        if (result < answer) answer = result;
        
        // 전력망 복구하기
        wire_matrix[v1][v2] = true;
        wire_matrix[v2][v1] = true;
    }
    
    return answer;
}










