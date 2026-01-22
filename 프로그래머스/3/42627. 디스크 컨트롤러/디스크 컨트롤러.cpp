#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Job
{
public:
    Job(int idx, int start_time, int len): idx(idx), start_time(start_time), len(len)
    {
        end_time = -1;
    }
    int get_turnaround_time()
    {
        return end_time - start_time;
    }
    bool operator < (const Job& right) const
    {
        if (len == right.len)
        {
            if (start_time == right.start_time)
            {
                return idx > right.idx;
            }
            else
            {
                return start_time > right.start_time;
            }
        }
        else
        {
            return len > right.len;
        }
    }
    void Print()
    {
        cout << "[" << idx << "] " << start_time << " to " << end_time << ", len: " << len << endl;
    }
    int idx;
    int start_time;
    int end_time;
    int len;
};

class JobQueue
{
public:
    JobQueue()
    {
        idx = 0;
    }
    void Push(int start_time, int len)
    {
        queue.emplace_back(idx, start_time, len);
        push_heap(queue.begin(), queue.end());
        idx += 1;
    }
    Job& Pop()
    {
        pop_heap(queue.begin(), queue.end());
        Job job = queue.back();
        queue.pop_back();
        done.emplace_back(job);
        return done.back();
    }
    int Len()
    {
        return queue.size();
    }
    
    int get_stat()
    {
        int total = 0;
        for (Job& job : done)
        {
            total += job.get_turnaround_time();
        }
        return total / done.size();
    }
    
private:
    vector<Job> queue;
    vector<Job> done;
    int idx;
};

bool comp(const vector<int>& left, const vector<int>& right)
{
    return left[0] < right[0];
}

int solution(vector<vector<int>> items)
{
    sort(items.begin(), items.end(), comp);
    
    JobQueue queue;
    int idx = 0;
    int current_time = 0;
    
    while (true)
    {
        // 현재 시간까지의 job을 모두 queue에 넣음
        while ((idx < items.size()) && items[idx][0] <= current_time)
        {
            queue.Push(items[idx][0], items[idx][1]);
            idx += 1;
        }
        
        // 다음 우선순위의 job을 꺼냄
        if (queue.Len() <= 0)
        {
            if (idx < items.size())
            {
                current_time = items[idx][0];
                continue;
            }
            else
            {
                break;   
            }
        }
        Job& next_job = queue.Pop();
        
        // 작업 진행
        if (current_time < next_job.start_time)
        {
            current_time = next_job.start_time;
        }
        current_time += next_job.len;
        next_job.end_time = current_time;
    }

    return queue.get_stat();
}
