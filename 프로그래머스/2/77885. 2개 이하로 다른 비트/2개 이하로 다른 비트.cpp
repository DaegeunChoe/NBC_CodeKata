#include <string>
#include <vector>

using namespace std;

/*
00[00] -> 00[01]
00[01] -> 00[10]
00[10] -> 00[11]
0[011] -> 0[100]
0[01]1 -> 0[10]0

01[00] -> 01[01] 4 -> 5
01[01] -> 01[10] 5 -> 6
01[10] -> 01[11] 6 -> 7 

[011]1 -> [101]1 7 -> 11
[01]11 -> [10]11 7 -> 11

좀 큰 수로 해볼까

010[00] -> 010[01]  8 -> 9
010[01] -> 010[10]  9 -> 10
010[10] -> 010[11] 10 -> 11
01[011] -> 01[101]
01[01]1 -> 01[10]1

[011]11 -> [101]11
[01]111 -> [10]111

01111
10000 5
10001 4
10010 4
10011 3
10100 4
10101 3
10110 3
10111 2
*/

long long f(long long x) {
    long long y=0;
    long long mask = 0x03; // b0011 마스크
    long long result = x & mask;    
    if (result == 0) {
        // b00 case -> b01
        y = x + (long long)(1);
    }
    else if (result == 1) {
        // b01 case -> b10
        y = x + (long long)(1);
    }
    else if (result == 2) {
        // b10 case -> b11
        y = x + (long long)(1);
    }
    else { // result == 3
        // b11 case
        // 가장 작은 b01 이 나타나는 구간을 찾는다.
        long long temp = x;
        long long r;
        int shift = 0;
        while (temp > 0) {
            temp = temp >> 1;
            shift += 1;
            r = temp & mask;
            if (r == 1) {
                y = x + ((long long)(1) << shift);
                break;
            }
        }
        
    }
    return y;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (auto& x : numbers) {
        answer.push_back(f(x));
    }
    return answer;
}