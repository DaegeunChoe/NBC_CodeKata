#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> split(string& in, char sep)
{
    vector<string> tokens;
    size_t pos = 0;
    size_t prev = 0;
    while (true)
    {
        prev = pos;
        pos = in.find(sep, pos);
        if (pos == string::npos)
        {
            break;
        }
        string token = in.substr(prev, pos-prev);
        tokens.emplace_back(token);
        pos += 1;
    }
    tokens.emplace_back(in.substr(prev));
    return tokens;
}

bool str_number_compare(const string& left, const string& right)
{
    if (left[0] == '-' && right[0] != '-')
    {
        return true;
    }
    else if (left[0] != '-' && right[0] == '-')
    {
        return false;
    }
    
    if (left[0] == '-') // && right[0] == '-'
    {
        if (left.size() > right.size())
        {
            return true;
        }
        else if (left.size() < right.size())
        {
            return false;
        }
        else
        {
            return left > right;
        }
    }
    else if (left[0] != '-') // && right[0] != '-'
    {
        if (left.size() > right.size())
        {
            return false;
        }
        else if (left.size() < right.size())
        {
            return true;
        }
        else
        {
            return left < right;
        }
    }
    
    return false;
}

string solution(string s) {
    vector<string> tokens = split(s, ' ');
    sort(tokens.begin(), tokens.end(), str_number_compare);
    string answer = "";
    answer += tokens[0];
    answer += " ";
    answer += tokens[tokens.size() - 1];
    return answer;
}