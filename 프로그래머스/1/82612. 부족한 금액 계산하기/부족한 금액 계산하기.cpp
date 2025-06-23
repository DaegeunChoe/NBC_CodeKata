using namespace std;

long long solution(int price, int money, int count)
{
    long long n = count;
    long long m = 2;
    long long total = ((n*n + n) / m);
    long long answer = ((long long)(price) * total) - ((long long)(money));
    if (answer > 0) {
        return answer;
    }
    else {
        return 0;
    }
}