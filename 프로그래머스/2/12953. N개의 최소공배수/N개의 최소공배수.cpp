#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    int size = arr.size();
    // for (int i=1; i<=150000; i++) {
    int i=0; while(true){ i++;
        bool check = true;
        for (int n=0; n<size; n++) {
            if (i % arr[n] != 0) {
                check = false;
                break;
            }
        }
        if (check) {
            answer = i;
            break;
        }
    }
    return answer;
}