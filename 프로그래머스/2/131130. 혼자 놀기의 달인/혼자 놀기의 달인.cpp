#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> cards) {
    // make group
    vector<int> groups(cards.size(), -1);
    int group = 1;
    for (int n=0; n<cards.size(); n++) {
        int from = n;
        while (true) {
            int to = cards[from] - 1;
            if (groups[to] != -1) {
                break;
            }
            else {
                groups[to] = group;
                from = to;
            }
        }
        group++;
    }
    
    // count group
    unordered_map<int, int> gorup_size;
    for (int& group : groups) {
        if (gorup_size.find(group) == gorup_size.end()) {
            gorup_size[group] = 0;
        }
        gorup_size[group]++;
    }
    vector<int> sizes;
    for (auto& item : gorup_size) {
        sizes.push_back(item.second);
    }
    sort(sizes.begin(), sizes.end());
    
    if (sizes.size() < 2) {
        return 0;
    }
    else {
        return sizes[sizes.size()-1] * sizes[sizes.size()-2];
    }
}