#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int len = numbers.size();
    
    vector<int> answer(len, -1);
    vector<int> index(len, -1);
    
    for (int n=len-2; n>=0; n--) {
        int k = n+1;
        while (k != -1) {
            int ak = numbers[k];
            if (numbers[n] < ak) {
                answer[n] = ak;
                index[n] = k;
                break;
            }
            k = index[k];
        }

    }
    return answer;
}