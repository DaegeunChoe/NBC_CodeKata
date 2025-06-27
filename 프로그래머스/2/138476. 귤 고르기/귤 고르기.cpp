#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    // 개수 세기
    unordered_map<int, int> count;
    for (int& t : tangerine) {
        if (count.find(t) == count.end()) {
            count[t] = 0;
        }
        count[t] += 1;
    }
    vector<int> list;
    for (auto& item : count) {
        list.push_back(item.second);
    }
    sort(list.begin(), list.end(), greater<int>());
    
    int answer = 0;
    for (int n=0; n<list.size(); n++) {
        k -= list[n];
        if (k <= 0) {
            answer = n + 1;
            break;
        }
    }
    return answer;
}