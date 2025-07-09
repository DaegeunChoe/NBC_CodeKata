#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    
    // 에라토스테네스의 체
    const int MAX = 3001;
    bool prime[MAX];
    for (int n=0; n<MAX; n++) {
         prime[n] = true;
    }
    prime[0] = false;
    prime[1] = false;
    for (int n=2; n<MAX; n++) {
        int r = n + n;
        if (prime[n]) {
            while (r < MAX) {
                prime[r] = false;
                r += n;
            }
        }
    }
        
    int answer = 0;
    int len = nums.size();
    
    for (int n0=0; n0<len; n0++) {
        for (int n1=n0+1; n1<len; n1++) {
            for (int n2=n1+1; n2<len; n2++) {
                int sum = nums[n0] + nums[n1] + nums[n2];
                if (prime[sum]) {
                    answer++;
                }
            }
        }
    }
    return answer;
}