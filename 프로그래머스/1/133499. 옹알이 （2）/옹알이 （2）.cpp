#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool canitem(string& bab, int index, string& item) {
    bool flag = true;
    int i = 0;
    while (index + i < bab.size() && i < item.size()) {
        if (bab[index + i] != item[i]) {
            flag = false;
            break;
        }
        i++;
    }
    if (i < item.size()) {
        flag = false;
    }
    return flag;
}

bool can(string& bab) {
    static string list[4] = {
        "aya", "ye", "woo", "ma"
    };
    int index=0;
    int before = -1;
    while (index < bab.size()) {
        bool flag = false;
        for (int n=0; n<4; n++) {
            if (before == n) {
                continue;
            }
            if (canitem(bab, index, list[n])) {
                flag = true;
                index += list[n].size();
                before = n;
                break;
            }
        }
        if (!flag) {
            return false;
        }
    }
    return true;
}

int solution(vector<string> babbling) {
    int answer = 0;
    for (string& bab : babbling) {
        if (can(bab)) {
            answer += 1;
        }
    }
    return answer;
}