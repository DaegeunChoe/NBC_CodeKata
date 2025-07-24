#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    int r = (int)(sqrt(n));
    for (int i=2; i < (r+1); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool can_make(int n, vector<int>& count1) {
    vector<int> count0(10, 0);
    while (n > 0) {
        int r = n % 10;
        n = n / 10;
        count0[r] += 1;
    }
    
    for (int i=0; i<10; i++) {
        if (count0[i] > count1[i]) {
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> count(10, 0);
    for (const char number : numbers) {
        count[number - '0'] += 1;
    }
    int pow = 1;
    for (int i = 0; i < numbers.size(); i++) {
        pow *= 10;
    }
    for (int n = 2; n < pow; n++) {
        if (can_make(n, count) && is_prime(n)) {
            answer += 1;
        }
    }
    
    return answer;
}