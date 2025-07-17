#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    
    vector<int> attack(number + 1, 0);
    
    for (int i = 1; i <= number; i++) {
        for (int n = i; n <= number; n += i) {
            attack[n] += 1;
        }
    }
    
    int answer = 0;
    for (int i = 1; i <= number; i++) {
        if (attack[i] > limit) {
            answer += power;
        }
        else {
            answer += attack[i];
        }
    }
    return answer;
}