#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    if (s.size()%2 == 0) {
        return string(s.begin() + (s.size()/2) - 1, s.begin() + (s.size()/2) + 1);
    }
    else {
        return string(s.begin() + (s.size()/2), s.begin() + (s.size()/2) + 1);
    }
}