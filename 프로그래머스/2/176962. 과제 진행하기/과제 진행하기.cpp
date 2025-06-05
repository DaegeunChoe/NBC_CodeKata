#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

class TimeUtils
{
public:
    static int TimeToMinute(string time)
    {
        int hour = StringToInt(string(time.begin(), time.begin()+2));
        int minute = StringToInt(string(time.begin()+3, time.begin()+5));
        return hour * 60 + minute;
    }
    static int StringToInt(string s)
    {
        int num = 0;
        const char* cs = s.c_str();
        for (int i=0; i<s.size(); i++)
        {
            num *= 10;
            num += cs[i] - '0';
        }
        return num;
    }
};

struct Assignment // 과제
{
    typedef int Minute;
    
    string Name;
    Minute StartTime;
    Minute PlayTime;
    Minute RemainTime;
    
    Assignment(vector<string>& input)
    {
        Name = input[0];
        StartTime = TimeUtils::TimeToMinute(input[1]);
        PlayTime = TimeUtils::StringToInt(input[2]);
        RemainTime = PlayTime;
    }
    
    bool operator < (Assignment& right) const 
    {
        return StartTime < right.StartTime;
    }
};

class AssignmentQueue
{
public:
    void Push(Assignment* n)
    {
        Queue.push_back(n);
    }
    Assignment* Pop()
    {
        Assignment* _b = Queue.back();
        Queue.pop_back();
        return _b;
    }
    Assignment* Top()
    {
        return Queue.back();
    }
    bool Empty()
    {
        return Queue.size() == 0;
    }
    vector<Assignment*> Queue;
};

void print(Assignment& a)
{
    cout << a.Name << ": " << a.StartTime << ", " << a.RemainTime << "/" << a.PlayTime << "..\n";
}


vector<string> solution(vector<vector<string>> Plans)
{
    vector<Assignment> List;
    for (auto& plan : Plans)
    {
        List.emplace_back(plan);
    }
    sort(List.begin(), List.end());
    
    // for (auto& a : List)
    // {
    //     print(a);
    // }
    
    int index = 0;
    AssignmentQueue AQueue;
    Assignment* Current = &List[index];
    Assignment::Minute StartTime = Current->StartTime;
    vector<string> answer;
    
    while (index < List.size() - 1)
    {
        Assignment* Next = &List[index + 1];
        Assignment::Minute ElapsedTime = Next->StartTime - StartTime;
        
        if (Current->RemainTime <= ElapsedTime)
        {
            // 과제 수행 완료
            ElapsedTime -= Current->RemainTime;
            Current->RemainTime = 0;
            answer.push_back(Current->Name);
            
            // 남아있는 시간 동안, 큐에 있는 과제를 할 수 있는가?
            while (!AQueue.Empty() && ElapsedTime > 0)
            {
                if (AQueue.Top()->RemainTime <= ElapsedTime)
                {
                    ElapsedTime -= AQueue.Top()->RemainTime;
                    AQueue.Top()->RemainTime = 0;
                    answer.push_back(AQueue.Top()->Name);
                    AQueue.Pop();
                }
                else // AQueue.Top()->RemainTime > ElapsedTime
                {
                    AQueue.Top()->RemainTime -= ElapsedTime;
                    ElapsedTime = 0;
                }
            }
            
            // 새 과제 시작
            Current = Next;
            StartTime = Current->StartTime;
            index += 1;
        }
        else // Current->RemainTime > ElapsedTime
        {
            // 과제를 내려놓고 새 과제를 시작해야 함
            Current->RemainTime -= ElapsedTime;
            ElapsedTime = 0;
            AQueue.Push(Current);
            Current = Next;
            StartTime = Current->StartTime;
            index += 1;
        }
    }
    
    // 현재 하고 있는 과제를 마무리
    if (Current->RemainTime > 0)
    {
        Current->RemainTime = 0;
        answer.push_back(Current->Name);
    }
    
    // 큐에 있는 과제 마무리
    while (!AQueue.Empty())
    {
        if (AQueue.Top()->RemainTime > 0)
        {
            AQueue.Top()->RemainTime = 0;
            answer.push_back(AQueue.Top()->Name);
        }
        AQueue.Pop();
    }
    
    return answer;
}