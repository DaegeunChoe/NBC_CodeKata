#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    long long answer = 0;
    for (int n=0; n<a.size(); n++) {
        long long _1 = a[n];
        long long _2 = b[n];
        answer += _1 * _2;
    }
    return answer;
}