#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for (int n=0; n<absolutes.size(); n++) {
        if (signs[n]) answer += absolutes[n];
        else answer -= absolutes[n];
    }
    return answer;
}