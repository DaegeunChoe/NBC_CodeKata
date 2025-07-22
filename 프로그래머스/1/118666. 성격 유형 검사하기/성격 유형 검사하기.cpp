#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey_list, vector<int> choices) {
    
    int statistics[26];
    statistics['R' - 'A'] = 0;
    statistics['T' - 'A'] = 0;
    statistics['C' - 'A'] = 0;
    statistics['F' - 'A'] = 0;
    statistics['J' - 'A'] = 0;
    statistics['M' - 'A'] = 0;
    statistics['A' - 'A'] = 0;
    statistics['N' - 'A'] = 0;
    
    int point_negative[7] = {3, 2, 1, 0, 0, 0, 0};
    int point_positive[7] = {0, 0, 0, 0, 1, 2, 3};
    
    for(int n=0; n<survey_list.size(); n++) {
        string survey = survey_list[n];
        const char negative = survey[0];
        const char positive = survey[1];
        
        int choice = choices[n];
        
        statistics[negative - 'A'] += point_negative[choice - 1];
        statistics[positive - 'A'] += point_positive[choice - 1];
    }
    
    string answer = "";
    if (statistics['R' - 'A'] >= statistics['T' - 'A']) {
        answer += "R";
    }
    else {
        answer += "T";
    }
    if (statistics['C' - 'A'] >= statistics['F' - 'A']) {
        answer += "C";
    }
    else {
        answer += "F";
    }
    if (statistics['J' - 'A'] >= statistics['M' - 'A']) {
        answer += "J";
    }
    else {
        answer += "M";
    }
    if (statistics['A' - 'A'] >= statistics['N' - 'A']) {
        answer += "A";
    }
    else {
        answer += "N";
    }
    return answer;
}