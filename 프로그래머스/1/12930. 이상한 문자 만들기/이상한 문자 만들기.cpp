#include <string>
#include <vector>

using namespace std;

char upper(const char n) {
    if ('a' <= n && n <= 'z') {
        return n + ('A' - 'a');
    }
    else {
        return n;
    }
}

char lower(const char n) {
    if ('A' <= n && n <= 'Z') {
        return n + ('a' - 'A');
    }
    else {
        return n;
    }
}

string solution(string s) {
    const char* in = s.c_str();
    char* out = new char[s.size()+1];
    int n = 0;
    for (int i=0; i<s.size(); i++) {
        
        if (in[i] == ' ') {
            out[i] = in[i];
            n = 0;
        }
        else {
            if (n%2==0) {
                out[i] = upper(in[i]);
            }
            else {
                out[i] = lower(in[i]);
            }
            n++;
        }
    }
    out[s.size()] = 0;
    string result(out);
    delete out;
    return result;
}