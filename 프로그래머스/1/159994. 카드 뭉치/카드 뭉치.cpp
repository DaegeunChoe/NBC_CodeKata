#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    
    int index_1 = 0;
    int index_2 = 0;
    int index_g = 0;
    
    bool c = true;
    while (index_g < goal.size()) {
        
        if (cards1[index_1] == goal[index_g]) {
            index_1 += 1;
            index_g += 1;
            continue;
        }
        if (cards2[index_2] == goal[index_g]) {
            index_2 += 1;
            index_g += 1;
            continue;
        }
        c = false;
        break;
    }
    
    if (c) {
        string answer = "Yes";
        return answer;
    }
    else {
        string answer = "No";
        return answer;
    }
    
}