#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;

    a -= 1;
    b -= 1;

    if (a > b) {
        int t = a;
        a = b;
        b = t;
    } 
    
    while (b > 0) {
        // cout << "(a, b): " << a << ", " << b << "\n";
        if (a % 2 == 0 && a + 1 == b) {
            break;
        }
        a >>= 1;
        b >>= 1;
        answer += 1;
    }
    return answer;
}