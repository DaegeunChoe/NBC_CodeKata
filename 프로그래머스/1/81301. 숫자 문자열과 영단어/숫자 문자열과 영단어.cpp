#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    string output = "";
    int idx = 0;
    int len = s.size();
    
    while (idx < len)
    {
        const char current = s[idx];
        if ('0' <= current && current <= '9')
        {
            output += current;
            idx += 1;
        }
        else
        {
            int pos;
            switch (current)
            {
            case 'z':
                output += '0';
                idx += 4;
                break;
            case 'o':
                output += '1';
                idx += 3;
                break;
            case 't':
                pos = s.find("two", idx);
                if (pos == idx)
                {
                    output += '2';
                    idx += 3;
                }
                pos = s.find("three", idx);
                if (pos == idx)
                {
                    output += '3';
                    idx += 5;
                }
                break;
            case 'f':
                pos = s.find("four", idx);
                if (pos == idx)
                {
                    output += '4';
                    idx += 4;
                }
                pos = s.find("five", idx);
                if (pos == idx)
                {
                    output += '5';
                    idx += 4;
                }
                break;
            case 's':
                pos = s.find("six", idx);
                if (pos == idx)
                {
                    output += '6';
                    idx += 3;
                }
                pos = s.find("seven", idx);
                if (pos == idx)
                {
                    output += '7';
                    idx += 5;
                }
                break;
            case 'e':
                output += '8';
                idx += 5;
                break;
            case 'n':
                output += '9';
                idx += 4;
                break;
            }
        }
    }
    
    int answer = stoi(output);
    return answer;
}