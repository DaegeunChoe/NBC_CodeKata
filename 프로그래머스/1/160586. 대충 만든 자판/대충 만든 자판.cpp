#include <string>
#include <vector>

#include <iostream>

using namespace std;

vector<int> solution(vector<string> Keymaps, vector<string> Targets) 
{
    vector<int> ShortestKey(26, -1);
    
    // 각 알파벳별로, 최단 입력 횟수를 구한다.
    for (string& Keymap : Keymaps)
    {
        for (int n = 0; n < Keymap.size(); n++)
        {
            int Index = Keymap[n] - 'A';
            if (ShortestKey[Index] == -1 || ShortestKey[Index] > (n + 1))
            {
                ShortestKey[Index] = n + 1;
            }
        }
    }
    
    // 답을 구한다.
    vector<int> Answer;
    for (string& Target : Targets)
    {
        int _a = 0;
        for (char& c : Target)
        {
            if (ShortestKey[c - 'A'] == -1)
            {
                _a = -1;
                break;
            }
            else
            {
                _a += ShortestKey[c - 'A'];
            }
        }
        Answer.push_back(_a);
    }
    
    
    return Answer;
}