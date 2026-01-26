#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    for (int item : arr)
    {
        if (answer.size() == 0 || answer.back() != item)
        {
            answer.push_back(item);
        }
    }
    
    return answer;
}