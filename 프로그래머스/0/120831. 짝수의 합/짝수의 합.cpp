#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    if (n%2 == 0) {
        return (n*n + n+n) / 4;
    }
    else {
        n -= 1;
        return (n*n + n+n) / 4;
    }
        
}