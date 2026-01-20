#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int solution(string s)
{
    int answer = 0;
    
    const char* input = s.c_str();
    int len = s.size();
    int idx = 0;
    char first_char = 0;
    int first_count;
    int other_count;
    
    while (idx < len)
    {
        char current = input[idx];
        if (first_char == 0)
        {
            first_char = current;
            first_count = 1;
            other_count = 0;
            idx += 1;
            continue;
        }
        else
        {
            if (current == first_char)
            {
                first_count += 1;
            }
            else
            {
                other_count += 1;
            }
            
            if (first_count == other_count)
            {
                answer += 1;
                idx += 1;
                first_char = 0;
                continue;
            }
            else
            {
                idx += 1;
                continue;
            }
        }
    }
    
    if (first_char != 0)
    {
        answer += 1;
    }
    
    return answer;
}