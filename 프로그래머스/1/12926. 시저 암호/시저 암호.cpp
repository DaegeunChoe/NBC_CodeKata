#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    const char* plain = s.c_str();
    char* cipher = new char[s.size()];
    
    for (int i=0; i<s.size(); i++) {
        if ('a' <= plain[i] && plain[i] <= 'z') {
            cipher[i] = ((plain[i] - 'a' + n) % 26) + 'a';
        }
        else if ('A' <= plain[i] && plain[i] <= 'Z') {
            cipher[i] = ((plain[i] - 'A' + n) % 26) + 'A';
        }
        else {
            cipher[i] = plain[i];
        }
    }
    
    string answer(cipher, s.size());
    delete[] cipher;
    return answer;
}