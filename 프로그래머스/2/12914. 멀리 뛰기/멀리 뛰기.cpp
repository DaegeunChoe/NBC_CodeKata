#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    
    vector<long long> foo(n);
    foo[0] = 1;
    foo[1] = 2;
    for (int i=2; i<n; i++) {
        foo[i] = (foo[i-1] + foo[i-2]) % 1234567;
    }
    return foo[n-1];
}