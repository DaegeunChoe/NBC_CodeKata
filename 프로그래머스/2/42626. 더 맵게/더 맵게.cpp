#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool Comp(const int& left, const int& right)
{
    return left > right;
}

int solution(vector<int> Scoville, int K)
{
    make_heap(Scoville.begin(), Scoville.end(), Comp);
    
    int Answer = 0;
    while (Scoville.size() >= 2)
    {
        pop_heap(Scoville.begin(), Scoville.end(), Comp);
        int Min_0 = Scoville.back();
        if (Min_0 >= K)
        {
            push_heap(Scoville.begin(), Scoville.end(), Comp);
            break;
        }
        else
        {
            Scoville.pop_back();   
        }
        
        pop_heap(Scoville.begin(), Scoville.end(), Comp);
        int Min_1 = Scoville.back();
        Scoville.pop_back();
        
        int New = Min_0 + Min_1 + Min_1;
        Scoville.push_back(New);
        push_heap(Scoville.begin(), Scoville.end(), Comp);
        
        Answer += 1;
    }
    
    if (Scoville.size() <= 1 && Scoville[0] < K)
    {
        return -1;
    }
    return Answer;
}