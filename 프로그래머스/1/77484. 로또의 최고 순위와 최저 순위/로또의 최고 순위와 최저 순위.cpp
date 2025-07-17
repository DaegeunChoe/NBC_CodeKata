#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    
    vector<bool> win_dict(46, false);
    for (int& n : win_nums) {
        win_dict[n] = true;
    }
    
    int fix = 0;
    int zero_count = 0;
    for (int& m : lottos) {
        if (win_dict[m]) {
            fix += 1;
        }
        else if (m == 0) {
            zero_count += 1;
        }
    }
    
    static int result[] = {6, 6, 5, 4, 3, 2, 1};
    
    vector<int> answer;
    answer.push_back(result[fix + zero_count]);
    answer.push_back(result[fix]);
    return answer;
}