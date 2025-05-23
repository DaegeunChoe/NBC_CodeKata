#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> Numbers)
{
    // 더하기
    vector<int> Adds;
    Adds.reserve(4950); // 100가지 중에서 2개를 선택하는 경우의 수는 100*99/2
    int Count = Numbers.size();
    for (int i = 0; i < Count; i++)
    {
        for (int j = i + 1; j < Count; j++)
        {
            Adds.push_back(Numbers[i] + Numbers[j]);
        }
    }
    
    // 정렬하기
    sort(Adds.begin(), Adds.end());
    
    // 중복 제거하기
    vector<int> Answer;
    Answer.push_back(Adds[0]);
    for (int i = 1; i < Adds.size(); i++)
    {
        if (Answer.back() != Adds[i])
        {
            Answer.push_back(Adds[i]);
        }
    }
    return Answer;
}