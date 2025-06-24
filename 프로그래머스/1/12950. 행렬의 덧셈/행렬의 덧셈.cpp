#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for (int r=0; r<arr1.size(); r++) {
        answer.emplace_back(arr1[r].size(), 0);
        for (int c=0; c<arr1[r].size(); c++) {
            answer[r][c] = arr1[r][c] + arr2[r][c];
        }
    }
    
    return answer;
}