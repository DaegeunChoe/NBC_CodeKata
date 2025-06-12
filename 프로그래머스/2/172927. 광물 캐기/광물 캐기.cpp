#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

// 이전 선택이 다음 선택에 영향을 주는 구조
// [다이아, 돌, 돌, 돌, 돌] 을 캐는 가장 효율적인 방법은 다이아 곡괭이지만,
// 다이아 곡괭이가 하나밖에 없을 때,
// 다음에 [다이아, 다이아, 다이아, 다이아, 다이아] 가 나온다면...?

struct Node {
    Node(int d, int i, int s, int c, int in)
        : dia(d), iron(i), stone(s), cost(c), index(in) {}
    int dia;
    int iron;
    int stone;
    int cost; // 피로도
    int index; // 광물 진행 상황
    
    bool operator <(const Node& right) const{
        return cost < right.cost;
    }
};

void get_min(int& answer, int value) {
    if (answer == -1) {
        answer = value;
    }
    if (answer > value) {
        answer = value;
    }
}

int solution(vector<int> picks, vector<string> minerals)
{
    int answer = -1;
    
    vector<Node> queue;
    queue.emplace_back(picks[0], picks[1], picks[2], 0, 0);
    
    while (queue.size() > 0) {
        pop_heap(queue.begin(), queue.end());
        Node current = queue.back();
        queue.pop_back();
        
        // cout << "current: picks[" 
        //      << current.dia << ", " << current.iron << ", " << current.stone << "], "
        //      << "minerals: (" << current.index << "/" << minerals.size() << "), "
        //      << "cost: " << current.cost << endl; 
        
        // 곡괭이를 전부 사용한 경우
        int pick_num = current.dia + current.iron + current.stone;
        if (pick_num <= 0) {
            get_min(answer, current.cost);
            continue;
        }
        // 모든 광물을 캔 경우
        if (current.index >= minerals.size()) {
            get_min(answer, current.cost);
            continue;
        }
        
        // 다음 광물
        int next_index = current.index + 5;
        if (next_index > minerals.size()) {
            next_index = minerals.size();
        }
        int dia_cost = 0;
        int iron_cost = 0;
        int stone_cost = 0;
        for (int n = current.index; n < next_index; n++) {
            if (minerals[n] == "diamond") {
                dia_cost += 1;
                iron_cost += 5;
                stone_cost += 25;
            }
            else if (minerals[n] == "iron") {
                dia_cost += 1;
                iron_cost += 1;
                stone_cost += 5;
            }
            else if (minerals[n] == "stone") {
                dia_cost += 1;
                iron_cost += 1;
                stone_cost += 1;
            }
        }
        
        if (current.dia > 0) {
            queue.emplace_back(
                current.dia - 1, current.iron, current.stone, 
                current.cost + dia_cost, next_index);
            push_heap(queue.begin(), queue.end());
        }
        if (current.iron > 0) {
            queue.emplace_back(
                current.dia, current.iron - 1, current.stone, 
                current.cost + iron_cost, next_index);
            push_heap(queue.begin(), queue.end());
        }
        if (current.stone > 0) {
            queue.emplace_back(
                current.dia, current.iron, current.stone - 1, 
                current.cost + stone_cost, next_index);
            push_heap(queue.begin(), queue.end());
        }
    }
    
    return answer;
}




