#include <string>
#include <vector>

using namespace std;

#include <iostream>

void Function(
    vector<vector<int>>& Users, 
    vector<int>& Emoticons,
    vector<int>& Rate,
    int& OutClientNum,
    int& OutMoney)
{
    OutClientNum = 0;
    OutMoney = 0;
    
    for (int u = 0; u < Users.size(); u++)
    {
        int tempMoney = 0;
        // 기준에 따라 전부 구매
        for (int e = 0; e < Emoticons.size(); e++)
        {
            if (Rate[e] >= Users[u][0])
            {
                tempMoney += (Emoticons[e] * (100 - Rate[e]) / 100);
            }
        }
        // 기준을 넘었다면, 서비스 가입
        if (tempMoney >= Users[u][1])
        {
            OutClientNum += 1;
        }
        // 그렇지 않는다면, 그냥 이모티콘 구매
        else
        {
            OutMoney += tempMoney;
        }
    }
}

vector<int> solution(vector<vector<int>> Users, vector<int> Emoticons)
{
    // 최우선 목표: 이모티콘 플러스 가입자 수를 최대한 늘리는 것
    // -> 최대 7개의 이모티콘의 할인율[10, 20, 30, 40]을 변경하여
    //    최대 100명의 유저를 가입시켜야 한다.
    // -> brute force 될 거 같은데? 4^7 = 2^14 = 1024*16 정도라
    vector<int> answer(2, 0);
    
    // 1<<2n = 2^2n = 4^n
    // 숫자를 이용해 모든 경우의 수를 만든다.
    int EmoticonNum = Emoticons.size();
    int MAX = 1 << (2 * EmoticonNum);
    vector<int> Rate(EmoticonNum); // 할인율
    for (int i = 0; i < MAX; i++)
    {
        int temp = i;
        for (int n = 0; n < EmoticonNum; n++)
        {
            Rate[n] = ((temp % 4) + 1) * 10;
            temp = temp / 4;
        }
        
        int ClientNum; // 가입자 수
        int Money; // 이모티콘 판매액
        Function(Users, Emoticons, Rate, ClientNum, Money);
        
        // cout << "할인율" << endl;
        // for (int n = 0; n < EmoticonNum; n++) cout << Rate[n] << ", ";
        // cout << endl;
        // cout << "결과: " << ClientNum << "명 가입, " << Money << "원 판매" << endl;
        
        // 최대 수치를 저장
        if (answer[0] < ClientNum || (answer[0] == ClientNum && answer[1] < Money))
        {
            answer[0] = ClientNum;
            answer[1] = Money;
        }
    }
    return answer;
}