#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if (arr.size() == 1) {
        answer.push_back(-1);
        return answer;
    }
    int min = -1;
    for (int i=0; i<arr.size(); i++) {
        if (min == -1 || arr[min] > arr[i]) {
            min = i;
        }
    }
   
    for (int i=0; i<arr.size(); i++) {
        if (i != min) {
            answer.push_back(arr[i]);
        }
    }
    return answer;
}