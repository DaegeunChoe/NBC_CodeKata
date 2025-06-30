#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    const char* ct = t.c_str();
    const char* cp = p.c_str();
    
    // window 만들기
    unsigned long long ten = 10;
    unsigned long long sum = 0;
    unsigned long long base = 1;
    int len = p.size();
    for (int n=0; n<len; n++) {
        sum *= ten;
        sum += (ct[n] - '0');
        base *= ten;
    }
    
    // p to int
    unsigned long long pint = 0;
    for (int n=0; n<len; n++) {
        pint *= ten;
        pint += (cp[n] - '0');
    }
    
    // window slide
    for (int n=0; n+len<=t.size(); n++) {
        if (pint >= sum) {
            answer++;
        }
        // cout << sum << ", " << (pint >= sum) << endl;
        sum *= ten;
        sum %= base;
        sum += (ct[n+len] - '0');
    }
    
    return answer;
}