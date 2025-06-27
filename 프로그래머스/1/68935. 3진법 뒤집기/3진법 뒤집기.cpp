#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    vector<int> threes;
    
    while (n > 0) {
        int r = n % 3;
        threes.push_back(r);
        n = n / 3;
    }
    
    int answer = 0;
    int pow = 1;
    for (int i=threes.size()-1; i>=0; i--) {
        answer += (pow * threes[i]);
        pow *= 3;
    }
    return answer;
}