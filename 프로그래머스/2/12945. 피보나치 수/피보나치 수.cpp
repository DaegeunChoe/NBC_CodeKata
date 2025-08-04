#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    vector<int> fibonachi(n+1);
    fibonachi[0] = 0;
    fibonachi[1] = 1;
    
    for (int i=2; i<=n; i++) {
        fibonachi[i] = fibonachi[i-1] + fibonachi[i-2];
        fibonachi[i] = fibonachi[i] % 1234567;
    }
    return fibonachi[n];
}