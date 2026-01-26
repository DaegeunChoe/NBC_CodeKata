#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> intermediate;
    int len = progresses.size();
    for (int idx = 0; idx < len; ++idx)
    {
        int progress = progresses[idx];
        int speed = speeds[idx];
        int remain = 100 - progress;
        int _r = remain % speed;
        int day = remain / speed + ( _r == 0 ? 0 : 1);
        intermediate.push_back(day);
    }
    
    vector<int> answer;
    int lastest;
    for (int idx = 0; idx < len; ++idx)
    {
        int current = intermediate[idx];
        if (answer.size() == 0)
        {
            answer.push_back(1);
            lastest = current;
            continue;
        }
        
        if (lastest < current)
        {
            answer.push_back(1);
            lastest = current;
        }
        else
        {
            answer[answer.size() - 1] += 1;
        }
    }
    return answer;
}