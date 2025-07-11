#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    int offset = 5;
    const char* day[7] = {
       "SUN","MON","TUE","WED","THU","FRI","SAT" 
    };
    int md[13] = {
        0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    }; 
    int sum = 0;
    for (int n=1; n<=12; n++) {
        sum += md[n];
        md[n] = sum;
    }
    return string(day[(offset + (b-1) + md[a-1]) % 7]);
}