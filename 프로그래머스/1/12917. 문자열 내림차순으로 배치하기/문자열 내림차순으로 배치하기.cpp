#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool foo(const char a, const char b) {
    return a > b;
}

string solution(string s) {
    sort(s.begin(), s.end(), foo);
    return s;
}