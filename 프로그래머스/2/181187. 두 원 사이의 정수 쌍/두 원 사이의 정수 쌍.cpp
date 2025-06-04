#include <string>
#include <vector>
#include <cmath>

#include <iostream>

using namespace std;

inline long long Function(long long nn)
{
    if (nn < 0)
    {
        return 0;
    }
    long long n = (long long)sqrt(nn);
    return n + 1;
}

long long solution(int _r1, int _r2)
{
    long long r1 = _r1;
    long long r2 = _r2;
    long long p1 = r1 * r1;
    long long p2 = r2 * r2;

    long long answer = 0;
    for (long long x=1; x<=r2; x++)
    {
        long long xx = x * x;
        long long a = p1 - (xx);
        long long b = p2 - (xx);
        long long yc = Function(b) - Function(a-1);
        // cout << "x: " << x << ", [a,b]: " << a << "," << b 
        //      << ", yc: " << yc << '\n'; 
        answer += yc;
    }
    return answer * 4;
}