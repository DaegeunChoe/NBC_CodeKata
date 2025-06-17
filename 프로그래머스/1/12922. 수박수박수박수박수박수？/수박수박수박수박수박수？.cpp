#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string watermelon = "수박";
    string answer = "";
    for (int i=0; i<n/2; i++) {
        answer += watermelon;
    }
    if (n%2 == 1) {
        answer += "수";
    }
    return answer;
}