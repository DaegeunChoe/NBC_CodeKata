#include <string>
#include <vector>

using namespace std;


vector<int> solution(vector<int> answers) {
    
    int num1[] = {1, 2, 3, 4, 5};
    int num2[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int num3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int a1 = 0, a2 = 0, a3 = 0;
    for (int n=0; n<answers.size(); n++) {
        if (answers[n] == num1[n % 5]) {
            a1 += 1;
        }
        if (answers[n] == num2[n % 8]) {
            a2 += 1;
        }
        if (answers[n] == num3[n % 10]) {
            a3 += 1;
        }
    }
    vector<int> answer;
    if (a1 == a2 && a2 == a3) {
        answer.push_back(1); answer.push_back(2); answer.push_back(3);
    }
    else {
        if (a1 == a2 && a2 > a3) {
            answer.push_back(1); answer.push_back(2);
        }
        else if (a2 == a3 && a3 > a1) {
            answer.push_back(2); answer.push_back(3);
        }
        else if (a3 == a1 && a1 > a2) {
            answer.push_back(1); answer.push_back(3);
        }
        else {
            if (a1 > a2 && a1 > a3) {
                answer.push_back(1);
            }
            else if (a2 > a1 && a2 > a3) {
                answer.push_back(2);
            }
            else if (a3 > a1 && a3 > a2) {
                answer.push_back(3);
            }
        }
    }
    return answer;
}