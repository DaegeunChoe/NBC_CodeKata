#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    int r;
    while(n>0)
    {
        r = n%10;
        answer += r;
        n = n/10;
    }

    return answer;
}