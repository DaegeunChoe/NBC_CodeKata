#include <string>
#include <vector>
#include <cmath>

#include <iostream>

using namespace std;

long long solution(int ik, int id) {
    long long answer = 0;
    long long k = ik;
    long long d = id;
    for (long long x = 0; x <= d; x += k) {
        long long y = sqrt(d*d - x*x);
        answer += ((y / k) + 1);
        // cout << "x: " << x << ", y: " << y << ", (y / k)=" << (y / k) << endl;   
    }
    return answer;
}