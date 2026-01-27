using namespace std;

/* 유클리드 호제법
gcd(a, b) = gcd(b, a%b) = g

Bgq + r = Ag
r = (A + Bq)g

Ag, Bg / Bg, (A + Bq)g

gcd(12, 8) = gcd(8, 12%8) = gcd(8, 7)
gcd(8, 4) = gcd(4, 0) -> 4

gcd(30, 12) = gcd(12, 6)

*/

long long get_gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long t = a;
        a = b;
        b = t % b;
    }
    return a;
}

long long solution(int w,int h)
{
    long long lw = w;
    long long lh = h;
    long long gcd = get_gcd(lw, lh);
    long long answer = (lw * lh) - (lw + lh - gcd);
    return answer;
}