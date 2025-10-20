#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct Info
{
    Info(int index, int count): index(index), count(count) {}
    int index;
    int count;
    
    bool operator < (const Info& right)
    {
        return count > right.count;
    }
};

struct Node
{
    Node()
    {
        total = 0;
    }
    
    int total;
    vector<Info> list;
    
    bool operator < (const Node& right)
    {
        return total > right.total;
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    map<string, Node> genres_statistics;
    for (int i=0; i < genres.size(); ++i)
    {
        string& key = genres[i];
        int value = plays[i];
        if (genres_statistics.find(key) == genres_statistics.end())
        {
            genres_statistics[key] = Node();
        }
        genres_statistics[key].total += value;
        genres_statistics[key].list.emplace_back(i, value);
    }
    
    vector<Node> alls;
    for (const auto& item : genres_statistics)
    {
        alls.push_back(item.second);
    }
    sort(alls.begin(), alls.end());
    
    vector<int> answer;
    for (Node& element : alls)
    {
        sort(element.list.begin(), element.list.end());
        
        answer.push_back(element.list[0].index);
        if (element.list.size() >= 2)
        {
            answer.push_back(element.list[1].index);
        }
    }
    return answer;
}