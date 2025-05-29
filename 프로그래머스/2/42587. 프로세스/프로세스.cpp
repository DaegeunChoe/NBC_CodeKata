#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct FProcess
{
    FProcess(int _priority, int _location)
    {
        priority = _priority;
        location = _location;
    }
    bool operator <(FProcess& Right) const
    {
        return priority < Right.priority;
    }
    int priority;
    int location;
};

int solution(vector<int> priorities, int location)
{
    queue<FProcess> processes;
    vector<FProcess> max_checker;
    for (int loc = 0; loc < priorities.size(); loc++)
    {
        processes.emplace(priorities[loc], loc);
        max_checker.emplace_back(priorities[loc], loc);
    }
    make_heap(max_checker.begin(), max_checker.end());
    
    // 문제 해결 시작
    int counter = 0;
    while (processes.size() > 0)
    {
        // 하나 꺼내기
        FProcess One = processes.front();
        processes.pop();
        
        // 최우선순위인가?
        if (One.priority == max_checker[0].priority)
        {
            // 실행한다.
            pop_heap(max_checker.begin(), max_checker.end());
            max_checker.pop_back();
            counter++;
            
            if (One.location == location) 
            {
                return counter;
            }
        }
        else
        {
            // 다시 집어넣는다.
            processes.push(One);
        }
        
    }
    return -1;
}




