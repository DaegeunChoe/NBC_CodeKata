#include <string>
#include <vector>

using namespace std;

#include <iostream>

/*
4[1, 7]7252841, 4
-> 1을 제거하는게 더 크다

[4, 7]7252841
->

77[2, 5]2841
->

775[2, 8]41
->

775841
*/

// 최악의 경우 (동일한 숫자 111...11 백만자리)
//   100만^2
// 겁나 긴 내림차순 (33333332222222221111111111)
// 

string solution(string number, int k) {
    
    const char* arr = number.c_str();
    
    // 최악의 경우만 필터링
    int map[10] = {0};
    for (int n=0; n<number.size(); n++) {
        map[arr[n] - '0'] = 1;
    }
    int sum = 0;
    for (int n=0; n<10; n++) {
        sum += map[n];
    }
    if (sum == 1) {
        int ans=0;
        for (int n=0; n<10; n++) {
            if (map[n] == 1) { ans=n; break; }
        }
        string answer = "";
        answer.append(number.size() - k, '0' + ans);
        return answer;
    }
    
    int i=0;
    int last_i=0;
    for (int n=0; n<k; n++) {
        // 4[17]7252841 과 같이, 증가하는 부분을 찾음
        bool b=true;
        i = last_i;
        while (i<number.size()-1)
        {
            while (arr[i] == '-') i++;
            int j = i+1;
            while (arr[j] == '-') j++;
            
            if ((arr[i] - '0') < (arr[j] - '0')) {
                number[i] = '-';
                b=false;
                last_i = i;
                while (arr[last_i] == '-') last_i--;
                if (last_i < 0) last_i = 0;
                break;
            }
            i = j;
        }
        // cout << number << endl;
        
        // 숫자 전체가 내림차순으로 배열된 경우
        if (b)
        {
            for (int m=1; m <= (k-n); m++)
            {
                number[number.size()-m] = '-';
            }
            break;
        }
    }
    
    string answer = "";
    const char* result = number.c_str();
    for (int n=0; n < number.size(); n++) {
        if (result[n] != '-')
            answer.append(1, result[n]);
    }
    return answer;
}