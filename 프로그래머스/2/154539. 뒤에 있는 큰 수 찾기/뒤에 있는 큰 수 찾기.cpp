#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int len = numbers.size();
    
    vector<int> answer(len, -1);
    vector<int> index(len, -1);
    
    for (int n=len-2; n>=0; n--) {
        
        int an0 = numbers[n];
        int an1 = numbers[n+1];
        
        if (an0 < an1) {
            answer[n] = an1;
            index[n] = n+1;
        }
        else {
            int k = index[n+1];
            while (k != -1) {
                int ak = numbers[k];
                if (an0 < ak) {
                    answer[n] = ak;
                    index[n] = k;
                    break;
                }
                k = index[k];
            }
        }
    }
    return answer;
}