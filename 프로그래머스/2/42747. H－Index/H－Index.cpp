#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> citations)
{
    // 오름차순으로 정렬
    sort(citations.begin(), citations.end(), greater<int>());
    int answer = 0;
    
    for (int i = 0; i < citations.size(); i++)
    {
        int n = i + 1;
        if (citations[i] >= n)
        {
            answer = n;
        }
        else 
        {
            break;
        }
    }
    
    return answer;
}