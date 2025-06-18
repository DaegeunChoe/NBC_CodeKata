#include <string>
#include <vector>

using namespace std;

struct Node {
    Node(int from, int to) : from(from), to(to) {}
    int from;
    int to;
};

#include <iostream>

int solution(vector<int> queue1, vector<int> queue2) {
    
    // 하나의 배열 만들기
    vector<int>& total = queue1;
    queue1.insert(queue1.end(), queue2.begin(), queue2.end());
    
    // 합 미리 계산하기
    vector<long long> sum_list;
    sum_list.push_back(0);
    long long sum = 0;
    for (int& e : total) {
        sum += e;
        sum_list.push_back(sum);
    }
    
    // 둘로 쪼갤 수 없는 경우
    if (sum_list.back() % 2 == 1) {
        return -1;
    }
    
    // 탐색
    int answer = -1;
    
    vector<Node> queue;
    queue.emplace_back(0, queue1.size()/2);
    while (queue.size() > 0) {
        Node current = queue.back();
        queue.pop_back();
        long long current_sum = sum_list[current.to]-sum_list[current.from];
        
        // cout << "(from,to) " << current.from << "," << current.to << " -> " << current_sum << endl;
        
        if (current_sum == sum_list.back()/2) {
            int movement = (current.from) + (current.to - (queue1.size()/2));
            if (answer == -1 || answer > movement) {
                answer = movement;
            }
        }
        else if (current_sum > sum_list.back()/2) {
            // queue1 사이즈를 줄인다. 
            if (current.from + 1 < current.to) {
                queue.emplace_back(current.from + 1, current.to);
            }
        }
        else { // current_sum < sum_list.back()/2
            // queue1 사이즈를 키운다.
            if (current.to + 1 < total.size()) {
                queue.emplace_back(current.from, current.to + 1);
            }
        }
    }
    return answer;
}