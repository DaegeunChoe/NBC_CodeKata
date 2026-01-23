#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int depth = 0;
    for (const char& ch : s)
    {
        if (ch == '(')
        {
            depth += 1;
        }
        else if (ch == ')')
        {
            if (depth <= 0)
            {
                return false;
            }
            depth -= 1;
        }
        else 
        {
            // unexpected
        }
    }


    return depth == 0;
}