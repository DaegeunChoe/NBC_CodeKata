#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;
    int sign = 1;
    const char* cstr = s.c_str();
    for (int n=0; n<s.size(); n++)
    {
        if (cstr[n] == '-' || cstr[n] == '+') 
        {
            sign *= (cstr[n] == '-' ? -1 : 1);
        }
        else
        {
            answer *= 10;
            answer += cstr[n] - '0';
        }

    }
    return answer * sign;
}