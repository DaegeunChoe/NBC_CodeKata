#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

struct FDate
{
    FDate(const string& InStr)
    {
        Year = stoi(InStr.substr(0, 4));
        Month = stoi(InStr.substr(5, 2));
        Day = stoi(InStr.substr(8, 2));
    }
    bool operator >(const FDate& Right)
    {
        int A = (Year * 28 * 12) + (Month * 28) + Day;
        int B = (Right.Year * 28 * 12) + (Right.Month * 28) + Right.Day;
        return A > B;
    }
    void AddDuration(short InMonth)
    {
        Month += InMonth;
        while (Month > 12)
        {
            Year += 1;
            Month -= 12;
        }
        
        Day -= 1;
        if (Day <= 0)
        {
            Day = 28;
            Month -= 1;
        }
        if (Month <= 0)
        {
            Year -= 1;
            Month = 12;
        }
    }
    
    short Year;
    short Month;
    short Day;
};

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    
    FDate Today(today);
    
    map<char, short> terms_dict;
    for (const string& term : terms)
    {
        char Type = term[0];
        string Duration_str = term.substr(2);
        short Duration_month = stoi(Duration_str);
        terms_dict[Type] = Duration_month;
    }
 
    vector<int> answer;
    
    for (int i=0; i<privacies.size(); i++)
    {
        const string& privacy = privacies[i];
        std::size_t pos = privacy.find(" ");
        string DateStr = privacy.substr(0, pos);
        char Type = privacy[pos + 1];
        FDate PrivacyDate(DateStr);
        
        PrivacyDate.AddDuration(terms_dict[Type]);
        
        if (Today > PrivacyDate)
        {
            answer.push_back(i + 1);
        }
    }
    
    
    return answer;
}






