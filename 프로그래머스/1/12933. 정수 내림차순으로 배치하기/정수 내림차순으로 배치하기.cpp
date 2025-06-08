#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    int arr[10] = {0};
    while (n > 0)
    {
        arr[n % 10] += 1;
        n = n / 10;
    }
    long long answer = 0;
    for (long long a=9; a>=0; a--)
    {
        for (int b=0; b<arr[a]; b++)
        {
            answer *= (long long)10;
            answer += a;
        }
    }
    return answer;
}