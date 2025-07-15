#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int paint_index = 0;
    int len = section.size();
    while (paint_index < len) {
        answer += 1;
        int i=1;
        while (paint_index+i < len && section[paint_index] + m > section[paint_index+i]) {
            i += 1;
        }
        paint_index += i;
    }
    
    return answer;
}