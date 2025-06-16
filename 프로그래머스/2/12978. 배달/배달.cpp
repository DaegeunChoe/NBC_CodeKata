#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    Node(int pos, int cost) : pos(pos), cost(cost) {}
    int pos;
    int cost;
    bool operator <(const Node& right) const {
        return cost > right.cost; // for min heap
    }
};

// 그래프 다익스트라
void solve_distance(int start, int size, vector<vector<int>>& matrix, vector<int>& distance) {
    
    vector<Node> queue;
    distance[0] = 0;
    queue.emplace_back(0, 0);
    
    while (queue.size() > 0) {
        pop_heap(queue.begin(), queue.end());
        Node current = queue.back();
        queue.pop_back();
        
        // 연결 지점 방문하기
        int from = current.pos;
        for (int to=0; to<size; to++) {
            int to_cost = current.cost + matrix[from][to];
            bool should = (distance[to] == -1) || (distance[to] > to_cost);
            if (matrix[from][to] > 0 && should) {
                queue.emplace_back(to, to_cost);
                push_heap(queue.begin(), queue.end());
                distance[to] = to_cost;
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {    
    // 인접행렬 만들기
    vector<vector<int>> matrix;
    for (int r=0; r<N; r++) {
        matrix.emplace_back(N, -1);
    }
    for (auto& r : road) {
        int from = r[0] - 1;
        int to = r[1] - 1;
        int cost = r[2];
        if (matrix[from][to] == -1 || matrix[from][to] > cost) {
            matrix[from][to] = cost;
        }
        if (matrix[to][from] == -1 || matrix[to][from] > cost) {
            matrix[to][from] = cost;
        }   
    }
    
    int answer = 1; // 1번 마을이 1번 마을에 배달하는 것은 언제나 가능
    vector<int> distance(N, -1);
    solve_distance(0, N, matrix, distance);
    
    // for (int n=0; n<N; n++) cout << "1부터 " << (n+1) << "까지의 거리: " << distance[n] << endl;
    
    for (int i=1; i<N; i++) {
        if (distance[i] <= K) {
            answer++;
        }
    }
    return answer;
}