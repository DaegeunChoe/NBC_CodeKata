#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int countp = 0;
    int county = 0;
    for (const char& ch : s)
    {
        if (ch == 'p' || ch == 'P')
        {
            countp += 1;
        }
        else if (ch == 'y' || ch == 'Y')
        {
            county += 1;
        }
    }
    return countp == county;
}