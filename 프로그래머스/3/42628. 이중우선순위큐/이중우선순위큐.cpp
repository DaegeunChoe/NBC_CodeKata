#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool Comp(const int& left, const int& right)
{
    return left > right;
}

class FDoublePriorityQueue
{
public:
    int size()
    {
        return ValidationSet.size();
    }
    
    void Push(int num)
    {
        MaxHeap.push_back(num);
        push_heap(MaxHeap.begin(), MaxHeap.end());
        
        MinHeap.push_back(num);
        push_heap(MinHeap.begin(), MinHeap.end(), Comp);
        
        ValidationSet.insert(num);
    }
    
    bool PopMax(int& Pop)
    {
        while (MaxHeap.size() > 0)
        {
            int Max = MaxHeap[0];
            pop_heap(MaxHeap.begin(), MaxHeap.end());
            MaxHeap.pop_back();
            if (ValidationSet.find(Max) == ValidationSet.end())
            {
                continue;
            }
            else
            {
                Pop = Max;
                ValidationSet.erase(Pop);
                return true;
            }
        }
        return false;
    }
    
    bool PopMin(int& Pop)
    {
        while (MinHeap.size() > 0)
        {
            int Min = MinHeap[0];
            pop_heap(MinHeap.begin(), MinHeap.end(), Comp);
            MinHeap.pop_back();
            if (ValidationSet.find(Min) == ValidationSet.end())
            {
                continue;
            }
            else
            {
                Pop = Min;
                ValidationSet.erase(Pop);
                return true;
            }
        }
        return false;
    }
    

private:
    vector<int> MaxHeap;
    vector<int> MinHeap;
    set<int> ValidationSet;
};

void Op(FDoublePriorityQueue& DoublePriorityQueue, string& operation)
{
    const char op = operation[0];
    const string num_str = operation.substr(2);
    int num = stoi(num_str);
    
    if (op == 'I')
    {
        DoublePriorityQueue.Push(num);
    }
    else if (op == 'D')
    {
        if (num == 1)
        {
            int Pop;
            DoublePriorityQueue.PopMax(Pop);
        }
        else if (num == -1)
        {
            int Pop;
            DoublePriorityQueue.PopMin(Pop);
        }
        else
        {
            // Unknown Op
        }
    }
    else
    {
        // Unknown Op
    }
}

vector<int> solution(vector<string> operations)
{
    vector<int> answer;
    FDoublePriorityQueue DoublePriorityQueue;
    for (string& operation : operations)
    {
        Op(DoublePriorityQueue, operation);
    }
    
    if (DoublePriorityQueue.size() <= 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else if (DoublePriorityQueue.size() == 1)
    {
        int One;
        DoublePriorityQueue.PopMax(One);
        answer.push_back(One);
        answer.push_back(One);
    }
    else
    {
        int Max, Min;
        DoublePriorityQueue.PopMax(Max);
        DoublePriorityQueue.PopMin(Min);
        answer.push_back(Max);
        answer.push_back(Min);
    }
    
    return answer;
}

