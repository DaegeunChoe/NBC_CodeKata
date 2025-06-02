#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    for (int q=1; q<n; q++)
    {
        if (n%q == 1)
        {
            return q;
        }
    }
    return -1;
}