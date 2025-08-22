#include <string>
#include <vector>
#include <iostream>

using namespace std;

short string_to_short(string in)
{
    short num = 0;
    for (const char& c : in)
    {
        num *= (short)10;
        num += (c - (short)'0');
    }
    return num;
}

class FRecords
{
public:
    vector<bool> IsValid;
    vector<short> InTime;
    vector<short> Time;
    vector<int> Fee;
    FRecords(): IsValid(10000, false), InTime(10000), Time(10000, 0), Fee(10000)
    {
    }
    
    void Add(string record)
    {
        string hour_string = record.substr(0, 2);
        string min_string = record.substr(3, 2);
        string index_string = record.substr(6, 4);
        const char info_prefix = record.substr(11, 1)[0];
        
        short hour = string_to_short(hour_string);
        short min = string_to_short(min_string);
        short time = (hour * (short)60) + min;
        short index = string_to_short(index_string);
        
        IsValid[index] = true;
        if (info_prefix == 'I')
        {
            InTime[index] = time;
        }
        else // info_prefix == 'O'
        {
            short ParkingTime = time - InTime[index];
            Time[index] += ParkingTime;
            InTime[index] = -1;
        }
    }
    
    void GetFee(short BaseTime, int BaseFee, short AddTime, int AddFee)
    {
        for (int i=0; i<10000; i++)
        {
            if (IsValid[i])
            {
                if (InTime[i] != -1)
                {
                    Time[i] += 1439 - InTime[i];
                }
                
                short TotalTime = Time[i];
                int TotalFee = BaseFee;
                
                // cout << "[i]: " << i << ", Time: " << TotalTime << endl;
                TotalTime -= BaseTime;
                
                if (TotalTime > 0)
                {
                    short q = TotalTime / AddTime;
                    short r = TotalTime % AddTime;
                    TotalFee += q * AddFee;
                    TotalFee += (r>0) ? AddFee : 0;
                }
                Fee[i] = TotalFee;
            }
        }
    }
    
    void GetResult(vector<int>* answer)
    {
        for (int i=0; i<10000; i++)
        {
            if (IsValid[i])
            {
                answer->push_back(Fee[i]);
            }
        }
    }
};

vector<int> solution(vector<int> fees, vector<string> records)
{
    
    FRecords Records;
    for (string& record : records)
    {
        Records.Add(record);
    }
    Records.GetFee(fees[0], fees[1], fees[2], fees[3]);
    
    vector<int> answer;
    Records.GetResult(&answer);
    return answer;
}