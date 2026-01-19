#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool CanEnter(int Stamina, vector<int>& DungeonInfo)
{
    int MinimumRequireStamina = DungeonInfo[0];
    return Stamina >= MinimumRequireStamina;
}

int Check(int Stamina, vector<int>& DungeonIndexs, vector<vector<int>>& DungeonInfos)
{
    int Count = 0;
    int RemainStamina = Stamina;
    
    for (int Index : DungeonIndexs)
    {
        vector<int>& DungeonInfo = DungeonInfos[Index];
        if (CanEnter(RemainStamina, DungeonInfo))
        {
            int RequireStamina = DungeonInfo[1];
            RemainStamina -= RequireStamina;
            Count += 1;
        }
        
        if (RemainStamina <= 0)
        {
            break;
        }
    }
    return Count;
}


int Search(int Loop, int Stamina, vector<vector<int>>& DungeonInfos)
{
    int Scale = DungeonInfos.size();
    vector<int> DungeonIndexs;
    for (int Exp = 0; Exp < Scale; ++Exp)
    {
        int And = (1<<Exp) & Loop;
        if (And)
        {
            DungeonIndexs.push_back(Exp);
        }
    }

    int max = -1;
    do
    {
        int result = Check(Stamina, DungeonIndexs, DungeonInfos);
        if (result > max)
        {
            max = result;
        }
    } while (next_permutation(DungeonIndexs.begin(), DungeonIndexs.end()));

    return max;
}

int solution(int k, vector<vector<int>> dungeons)
{
    int answer = -1;
    int Scale = dungeons.size();
    for (int Loop = 1; Loop < (1<<Scale); ++Loop)
    {
        int result = Search(Loop, k, dungeons);
        if (result > answer)
        {
            answer = result;
        }
    }
    return answer;
}