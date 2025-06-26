#include <string>
#include <vector>

using namespace std;

int gcd(int A, int B) {
    if (A < B) {
        return gcd(B, A);
    }
    while (B != 0) {
        int r = A % B;
        A = B;
        B = r;
    }
    return A;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    int G = gcd(n, m);
    answer.push_back(G);
    answer.push_back(n * m / G);
    return answer;
}