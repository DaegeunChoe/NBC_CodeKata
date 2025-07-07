#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {

    // skip 정보
    vector<bool> skip_dict(26, false);
    const char* skip_c = skip.c_str();
    for (int n=0; n<skip.size(); n++) {
        skip_dict[skip_c[n] - 'a'] = true;
    }
    
    // 건너뛰기
    const char* from = s.c_str();
    string answer = "";
    for (int n=0; n<s.size(); n++) {
        int a = from[n] - 'a';
        for (int i=0; i<index; i++) {
            do {
                a++;
                if (a >= 26) a = 0;
            } while(skip_dict[a]);
        }
        answer += (a + 'a');
    }
    return answer;
}