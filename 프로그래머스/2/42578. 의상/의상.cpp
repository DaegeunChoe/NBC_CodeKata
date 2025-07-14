#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> clothes_map;
    for (auto& cloth_info : clothes) {
        string category = cloth_info[1];
        
        if (clothes_map.find(category) == clothes_map.end()) {
            clothes_map[category] = 0;
        }
        clothes_map[category] += 1;
    }
    vector<int> count;
    for (auto& cl : clothes_map) {
        count.push_back(cl.second);
    }
    
    int n = count.size();
    int answer = 0;
    
    for (int k=0; k<n; k++) {
        answer += (count[k] + (count[k]) * answer);
    }
    return answer;
}