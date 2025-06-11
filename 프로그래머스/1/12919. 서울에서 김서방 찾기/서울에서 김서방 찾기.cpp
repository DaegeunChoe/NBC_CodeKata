#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    int n=0;
    for (; n<seoul.size(); n++)
    {
        if (seoul[n] == "Kim")
        {
            break;
        }
    }
    string answer = "김서방은 ";
    answer.append(to_string(n));
    answer.append("에 있다");
    return answer;
}