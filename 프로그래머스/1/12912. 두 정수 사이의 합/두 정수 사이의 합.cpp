#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b)
{
    long long count = (a > b ? a-b : b-a) + 1;
    return ((a + b)*(count))/2;
}