#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> queue;
    
    for (int n=0; n<ingredient.size(); n++) {
        queue.push_back(ingredient[n]);
        if (queue.size() >= 4 
            && queue[queue.size() - 4] == 1
            && queue[queue.size() - 3] == 2
            && queue[queue.size() - 2] == 3
            && queue[queue.size() - 1] == 1) {
            
            answer += 1;
            queue.pop_back();
            queue.pop_back();
            queue.pop_back();
            queue.pop_back();
        }
    }

    return answer;
}