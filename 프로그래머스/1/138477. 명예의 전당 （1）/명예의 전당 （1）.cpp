#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> min_heap;
    for (int s : score) {
        min_heap.push_back(s);
        push_heap(min_heap.begin(), min_heap.end(), greater<>{});
        if (min_heap.size() > k) {
            pop_heap(min_heap.begin(), min_heap.end(), greater<>{});
            min_heap.pop_back();
        }
        answer.push_back(min_heap[0]);
    }
    return answer;
}