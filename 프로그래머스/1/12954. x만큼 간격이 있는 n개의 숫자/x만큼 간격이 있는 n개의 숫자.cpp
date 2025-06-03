#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n)
{
    vector<long long> answer;
    long long _x = x;
    for (long long i=1; i<=n; i++)
    {
        answer.push_back(_x * i);
    }
    return answer;
}