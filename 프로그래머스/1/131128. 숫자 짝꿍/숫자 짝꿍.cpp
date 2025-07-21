#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    
    vector<int> numx(10, 0);
    vector<int> numy(10, 0);
    
    for (int i=0; i<X.size(); i++) {
        numx[X[i] - '0'] += 1;
    }
    for (int i=0; i<Y.size(); i++) {
        numy[Y[i] - '0'] += 1;
    }
    
    string answer = "";
    for (int i=9; i>=1; i--) {
        int min = (numx[i] > numy[i]) ? numy[i] : numx[i];
        if (min > 0) {
            answer += string(min, '0' + i);
        }
    }
    {
        int min = (numx[0] > numy[0]) ? numy[0] : numx[0];
        if (min > 0) {
            if (answer.size() > 0) {
                answer += string(min, '0');
            }
            else {
                answer += string(1, '0');
            }
        }
    }
    if (answer.size() > 0) {
        return answer;
    }
    else {
        return string("-1");
    }
}