#include <string>
#include <vector>

using namespace std;

string f1(string in, int* rm_zero) {
    int one = 0;
    for (int i=0; i<in.size(); i++) {
        if (in[i] == '1') {
            one++;
        }
    }
    *rm_zero += in.size() - one;
    return string(one, 1);
}

string f2(int len) {
    // int to string (base 2)
    string result = "";
    while (len > 0) {
        int r = len & 0x01;
        result = result + (r == 1 ? "1" : "0");
        len = len >> 1;
    }
    return result;
}

vector<int> solution(string s) {
    
    int rm_zero = 0;
    int count = 0;
    string t = s;
    while (true) {
        t = f1(t, &rm_zero);
        t = f2(t.size());
        count++;
        if (t == "1") {
            break;
        }
    }
    
    vector<int> answer;
    answer.push_back(count);
    answer.push_back(rm_zero);
    return answer;
}