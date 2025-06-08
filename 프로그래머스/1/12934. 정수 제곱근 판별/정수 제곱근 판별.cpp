#include <string>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long root = sqrt(n); 
    if (root * root == n)
    {
        return (root + 1)*(root + 1);
    }
    else 
    {
        return -1;
    }
}