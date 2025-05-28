#include <string>
#include <vector>

using namespace std;

vector<int> solution(int N, long long Left, long long Right)
{
    vector<int> Answer;
    Answer.reserve(Right - Left + 1);
    
    for (long long i = Left; i <= Right; i++)
    {
        long long a, b;
        a = i / N;
        b = i - a * N;
        Answer.push_back(a > b ? a+1 : b+1);
    }
    
    return Answer;
}