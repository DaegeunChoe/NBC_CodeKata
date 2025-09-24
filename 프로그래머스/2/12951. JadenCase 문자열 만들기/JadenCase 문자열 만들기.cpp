#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    int len = s.size();
    const char* from = s.c_str();
    char* to = new char[len + 1];
    to[len] = 0;
    bool flag = true;
    
    for (int i = 0; i < len; i++)
    {
        if (from[i] != ' ')
        {
            if (flag)
            {
                flag = false;
                if ('a' <= from[i] && from[i] <= 'z')
                {
                    to[i] = from[i] - ('a' - 'A');
                }
                else
                {
                    to[i] = from[i];
                }
            }
            else
            {
                if ('A' <= from[i] && from[i] <= 'Z')
                {
                    to[i] = from[i] + ('a' - 'A');
                }
                else
                {
                    to[i] = from[i];
                }
            }
        }
        else // from[i] == ' '
        {
            flag = true;
            to[i] = from[i];
        }
    }
    
    string answer(to);
    delete[] to;
    return answer;
}