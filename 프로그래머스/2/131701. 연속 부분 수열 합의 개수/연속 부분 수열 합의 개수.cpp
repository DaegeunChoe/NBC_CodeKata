#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> elements) {
    int size = elements.size();
    vector<bool> dict(size * 1000, false);
    
    int total = 0;
    for (int i=0; i<size; i++) {
        total += elements[i];
    }
    dict[total] = true;
    for (int n=1; n<=size/2; n++) {
        cout << "n: " << n << "\n";
        for (int start=0; start<size; start++) {
            int sub_total = 0;
            for (int i=0; i<n; i++) {
                int index = (start + i) % size;
                sub_total += elements[index];
            }
            dict[sub_total] = true;
            dict[total - sub_total] = true;
            // cout << (sub_total) << ", " << (total - sub_total) << "\n";
        }
    }
    
    int answer = 0;
    for (int i=0; i<=total; i++) {
        if (dict[i]) {
            answer += 1;
        }
    }
    return answer;
}