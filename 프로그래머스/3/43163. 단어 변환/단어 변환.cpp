#include <string>
#include <vector>
#include <list>
#include <map>
#include <iostream>

using namespace std;

struct Node
{
public:
    Node(string word, int depth): word(word), depth(depth)
    {
    }
    string word;
    int depth;
};

bool convertable(string& from, string& to)
{
    if (from.size() != to.size())
    {
        return false;
    }
    
    int len = from.size();
    int diff = 0;
    for (int idx = 0; idx < len; ++idx)
    {
        if (from[idx] != to[idx])
        {
            diff += 1;
        }
    }
    
    if (diff == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int solution(string begin, string target, vector<string> words)
{
    map<string, bool> history;
    for (string& word : words)
    {
        history[word] = false;
    }
    
    list<Node> queue;
    queue.emplace_back(begin, 0);
    
    while (queue.size() > 0)
    {
        Node current = queue.front();
        queue.pop_front();
        history[current.word] = true;
        
        // cout << "current: " << current.word << ", " << current.depth << endl;
        
        if (current.word == target)
        {
            return current.depth;
        }
        
        for (string& word : words)
        {
            if (!history[word] && convertable(current.word, word))
            {
                queue.emplace_back(word, current.depth + 1);
            }
        }
    }
    
    return 0;
}