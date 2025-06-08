#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int q = x;
    int sum = 0;
    while (x>0)
    {
        sum += x % 10;
        x = x/10;
    }
    return (q % sum) == 0;
}