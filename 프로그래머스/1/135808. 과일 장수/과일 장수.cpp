#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int len = score.size();
    sort(score.begin(), score.end(), greater());
    
    for (int n=0; n+m<=len; n+=m) {
        int min = k+1;
        for (int i=0; i<m; i++) {
            if (min > score[n+i]) {
                min = score[n+i];
            }
        }
        // cout << "min: " << min << endl;
        answer += min * m;
    }
    
    return answer;
}