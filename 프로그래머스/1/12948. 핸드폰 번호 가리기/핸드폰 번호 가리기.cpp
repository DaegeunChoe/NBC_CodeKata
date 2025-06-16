#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer(phone_number.size()-4, '*');
    string add(phone_number.begin()+(phone_number.size()-4), phone_number.end());
    answer.append(add);
    return answer;
}