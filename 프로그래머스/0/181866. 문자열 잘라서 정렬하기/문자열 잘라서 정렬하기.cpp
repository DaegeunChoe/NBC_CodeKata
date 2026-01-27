#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> solution(string myString)
{
    stringstream ss(myString);
    string token;
    vector<string> answer;
    
    while (getline(ss, token, 'x'))
    {
        if (token.size() > 0)
        {
            answer.emplace_back(token);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}