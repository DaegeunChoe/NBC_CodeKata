#include <string>
#include <vector>

using namespace std;

// 약수의 개수 세기
int func(int input) {
    int count = 0;
    for (int n=1; n<=input; n++) {
        if (input % n == 0) {
            count += 1;
        }
    }
    return count;
}

int solution(int left, int right) {
    int answer = 0;
    
    for (int n=left; n<=right; n++) {
        if (func(n) % 2 == 0) {
            answer += n;
        }
        else {
            answer -= n;
        }
    }
    return answer;
}