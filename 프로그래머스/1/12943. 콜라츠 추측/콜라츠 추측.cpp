#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long N = num;
    int answer = 0;
    while(N != 1)
    {
        if (answer >= 500)
        {
            return -1;
        }
        if (N % 2 == 0)
        {
            N /= 2;
        }
        else
        {
            N = N * 3 + 1;
        }
        answer += 1;
    }
    return answer;
}