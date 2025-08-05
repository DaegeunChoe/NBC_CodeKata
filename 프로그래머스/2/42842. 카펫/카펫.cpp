#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    
    int sum = (brown / 2) + 2;
    int mul = brown + yellow;
    
    int h = 1;
    
    vector<int> answer;
    while (h < 2000) {
        int w = mul / h;
        if ((w*h == mul) && (w + h == sum)) {
            answer.push_back(w);
            answer.push_back(h);
            break;
        }
        h++;
    }
    return answer;
}