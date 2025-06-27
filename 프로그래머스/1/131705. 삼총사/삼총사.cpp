#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    // 부르트포스마렵네
    int answer = 0;
    int size = number.size();
    for (int n0=0; n0<size; n0++) {
        for (int n1=n0+1; n1<size; n1++) {
            for (int n2=n1+1; n2<size; n2++) {
                if ((number[n0] + number[n1] + number[n2]) == 0) {
                    answer += 1;
                }
            }
        }
    }
    return answer;
}