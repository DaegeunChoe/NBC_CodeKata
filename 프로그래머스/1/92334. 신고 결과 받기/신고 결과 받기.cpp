#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report_list, int k) {
    
    map<string, int> count;
    map<string, set<string>> report_map; 
    for (const string& id : id_list)
    {
        count[id] = 0;
    }
    
    for (const string& report : report_list)
    {
        int sep = report.find(' ');
        string from = report.substr(0, sep);
        string to = report.substr(sep + 1);
        
        if (report_map.find(to) == report_map.end())
        {
            report_map[to] = set<string>();
        }
        report_map[to].insert(from);
    }
    
    for (const string& id : id_list)
    {
        if (report_map.find(id) == report_map.end())
        {
            continue;
        }
        if (report_map[id].size() >= k)
        {
            for (const string& from : report_map[id])
            {
                count[from] += 1;
            }
        }
    }
    
    vector<int> answer;
    for (const string& id : id_list)
    {
        answer.push_back(count[id]);
    }
    return answer;
}