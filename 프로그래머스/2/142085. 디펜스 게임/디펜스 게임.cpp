#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

int _BS(unsigned long long Hero, vector<unsigned long long>& SumArray, int Left, int Right)
{
    int Mid = (Left + Right) / 2;
    if (Left == Right)
    {
        return Mid;
    }
    else
    {
        if (SumArray[Mid] > Hero)
        {
            return _BS(Hero, SumArray, Left, Mid);
        }
        else // SumArray[Mid] <= Hero
        {
            return _BS(Hero, SumArray, Mid + 1, Right);
        }
    }
}

int FindCanClearRoundCount(unsigned long long Hero, vector<unsigned long long>& SumArray)
{
    if (Hero >= SumArray[SumArray.size()-1])
    {
        return SumArray.size();
    }
    else
    {
        return _BS(Hero, SumArray, 0, SumArray.size()-1);
    }
}


int solution(int _Hero, int Ult, vector<int> enemy)
{
    vector<unsigned long long> SumArray(enemy.size(), 0);
    unsigned long long Hero = _Hero;
    SumArray[0] = enemy[0];
    for (int n=1; n<enemy.size(); n++)
    {
        SumArray[n] = SumArray[n-1] + (unsigned long long)enemy[n];
    }
    
    // for (int n=0; n<SumArray[SumArray.size()-1] + 4;n++)
    //     cout << n << ',' << FindCanClearRoundCount(n, SumArray) << '\n';
    // 특이 케이스
    // 1. 무족권으로 전부스킵 가능
    if (Ult == enemy.size()) 
    {
        return enemy.size(); 
    }
    // 2. 스킵권 사용 없이 클리어 가능
    if (Hero >= SumArray[SumArray.size()-1])
    {
        return enemy.size(); 
    }
    
    int RemainUlt = Ult;
    int RoundIndex = 0; // for heap
    vector<int> MaxHeap;
    while (RemainUlt > 0)
    {   
        // 현재 병사 수를 가지고 깰 수 있는 최대 라운드 개수 구하기
        int CanClearRoundCount = FindCanClearRoundCount(Hero, SumArray);
        
        // 현재 남은 병사로 올 클리어 가능
        if (CanClearRoundCount == enemy.size())
        {
            return enemy.size();
        }
         
        // 도전할 수 있는 라운드 중에서, 적의 수가 가장 많은 라운드 찾기
        // maxheap 사용
        while (RoundIndex < CanClearRoundCount + 1)
        {
            MaxHeap.push_back(enemy[RoundIndex]);
            push_heap(MaxHeap.begin(), MaxHeap.end());
            RoundIndex += 1;
        }
        pop_heap(MaxHeap.begin(), MaxHeap.end());
        int MaxEneny = MaxHeap.back();
        MaxHeap.pop_back();
        
        // 무적권으로 스킵한다는 것 == 병사 수를 그만큼 늘리는 것
        Hero += MaxEneny;
        RemainUlt -= 1;
    }

    // 마무리
    int CanClearRoundCount = FindCanClearRoundCount(Hero, SumArray);
    return CanClearRoundCount;
}


