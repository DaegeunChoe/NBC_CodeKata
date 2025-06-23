#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    
    int len = s.size();
    
    if ((len == 4 || len == 6)) {
        const char* c = s.c_str();
        for (int n=0; n<len; n++) {
            if (!(c[n] >= '0' && c[n] <= '9')) {
                return false;
            }
        }
        return true;
    }
    else {
        return false;
    }
}