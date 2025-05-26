#include <string>
#include <vector>

// #include <iostream>

using namespace std;

int solution(int N, vector<int> Lost, vector<int> Reserve)
{
    // 여벌 체육복이 있는 학생 정보를 먼저 구한다.
    // 도난 당한 경우를 체크해서, 제거해야 한다.
    vector<int> Stock(N + 1, 1);
    for (int& r : Reserve)
    {
        Stock[r] += 1; 
    }
    for (int& l : Lost)
    {
        Stock[l] -= 1; 
    }
    
    // 선택지가 없는 경우부터
    for (int i = 1; i <= N; i++)
    {
        // 나누어 줄 수 있으며
        if (Stock[i] > 1)
        {
            // 내 앞 뒤 중에서, 딱 한명 만 옷이 없는 경우
            bool frontLost = i == 1 ? false : Stock[i - 1] == 0;
            bool backLost = i == N ? false :  Stock[i + 1] == 0;
            if (frontLost && !backLost)
            {
                Stock[i]--;
                Stock[i - 1]++;
            }
            else if (!frontLost && backLost)
            {
                Stock[i]--;
                Stock[i + 1]++;
            }
        }
    }
    
    // 선택지가 있는 경우
    // 남은 아무에게나 옷을 빌려주어도 된다.
     for (int i = 1; i <= N; i++)
    {
        // 나누어 줄 수 있으며
        if (Stock[i] > 1)
        {
            // 내 앞 뒤 중에서, 옷이 없는 사람 아무에게나 주어도 된다.
            bool frontLost = i == 1 ? false : Stock[i - 1] == 0;
            bool backLost = i == N ? false :  Stock[i + 1] == 0;
            if (frontLost)
            {
                Stock[i]--;
                Stock[i - 1]++;
            }
            else if (backLost)
            {
                Stock[i]--;
                Stock[i + 1]++;
            }
        }
     }
    
    // for (int i=1; i<=N; i++)
    //     cout << i << ':' << Stock[i] <<'\n';
    
    int Answer = 0;
    for (int i = 1; i <= N; i++)
    {
        if (Stock[i] > 0)
        {
            Answer++;
        }
    }
    return Answer;
}