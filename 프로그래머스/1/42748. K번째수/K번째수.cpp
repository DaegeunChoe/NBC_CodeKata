#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> Array, vector<vector<int>> Commands) 
{
    vector<int> Answer;
    for (auto& Command : Commands)
    {
        int _from = Command[0] - 1;
        int _to = Command[1] - 1;
        int _index = Command[2] - 1;
        vector<int> Copy;
        for (int i = _from; i <= _to; i++)
        {
            Copy.push_back(Array[i]);
        }
        sort(Copy.begin(), Copy.end());
        Answer.push_back(Copy[_index]);
    }
    return Answer;
}