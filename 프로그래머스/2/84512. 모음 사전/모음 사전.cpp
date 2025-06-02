#include <string>
#include <vector>

using namespace std;



int solution(string word)
{
    int sum[5] = {781, 156, 31, 6, 1}; // 1+5+25+125+625
    int map[26] = {0};
    map['A' - 'A'] = 0;
    map['E' - 'A'] = 1;
    map['I' - 'A'] = 2;
    map['O' - 'A'] = 3;
    map['U' - 'A'] = 4;
    int answer = 0;
    
    for (int i=0; i<word.size(); i++)
    {
        answer += map[word[i] - 'A'] * sum[i] + 1;
    }
    return answer;
}








