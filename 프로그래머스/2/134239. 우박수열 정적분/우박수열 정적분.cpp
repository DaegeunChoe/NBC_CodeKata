#include <string>
#include <vector>

using namespace std;

// 우박수 시뮬레이션 함수
void DoCollatz(vector<int>& array, int start)
{
    int cursor = start;
    array.push_back(cursor);
    while(cursor > 1)
    {
        if (cursor % 2 == 0)
        {
            cursor = cursor / 2;
        }
        else
        {
            cursor = cursor * 3 + 1;
        }
        array.push_back(cursor);
    }
}

vector<double> solution(int k, vector<vector<int>> ranges)
{
    // 우박수 구하기
    vector<int> CollatzArray;
    DoCollatz(CollatzArray, k);
    
    // 사다리꼴 넓이 구하기 (나누기 안함, 2배값)
    vector<int> AreaArray(CollatzArray.size()-1);
    for (int n=0; n<CollatzArray.size()-1; n++)
    {
        AreaArray[n] = CollatzArray[n] + CollatzArray[n+1];
    }
    
    // 정적분하기
    vector<double> answer;
    for (auto& range : ranges)
    {
        int a = range[0];
        int b = AreaArray.size() + range[1];
        if (a > b)
        {
            answer.push_back(-1);
            continue;
        }
        
        int sum = 0;
        for (int n=a; n<b; n++)
        {
            sum += AreaArray[n];
        }
        answer.push_back(sum / 2.0);
    }
    

    return answer;
}