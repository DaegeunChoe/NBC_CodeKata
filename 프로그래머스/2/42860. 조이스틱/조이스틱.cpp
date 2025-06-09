#include <string>
#include <vector>

using namespace std;

#include <iostream>

int solution(string name) {
    if (name == "A")
    {
        return 0;
    }
    const char* Arr = name.c_str();
    int len = name.size();
    
    // 고정 비용
    int fix = 0;
    for (int n=0; n<len; n++)
    {
        int distance = Arr[n] - 'A';
        fix += (distance <= 13 ? distance : 26 - distance);
    }
    
    // 변동 비용 - 최소값을 찾아야 함
    int minCost = -1;
    for (int n=0; n<len; n++)
    {
        // 고리 안에서 min/max 사이의 거리를 계산해야 함
        int min = -1;
        int max = -1;
        int full;
        
        // 정방향
        for (int i=0; i<len; i++)
        {
            int c = (n + i)%len;
            if (Arr[c] != 'A')
            {
                min = (min == -1) ? (i) : (min > i ? i : min);
                max = (max == -1) ? (i) : (max < i ? i : max);
            }
        }
        full = (max - min) 
             + (n <= len/2 ? n : len - n)
             + (min<(len-max)?min:(len-max));
        if (minCost == -1) minCost = full;
        minCost = full > minCost ? minCost : full;

        // 역방향
        min = -1;
        max = -1;
        for (int i=0; i<len; i++)
        {
            int c = (n - i + len)%len;
            if (Arr[c] != 'A')
            {
                min = (min == -1) ? (i) : (min > i ? i : min);
                max = (max == -1) ? (i) : (max < i ? i : max);
            }
        }
        full = (max - min) 
             + (n <= len/2 ? n : len - n)
             + (min<(len-max)?min:(len-max));
        if (minCost == -1) minCost = full;
        minCost = full > minCost ? minCost : full;
    }
    return fix + minCost;
}