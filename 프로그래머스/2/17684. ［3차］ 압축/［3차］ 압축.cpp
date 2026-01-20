#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Node
{
public:
    Node(): indexes(26), next(26)
    {
        for (int idx = 0; idx < 26; ++idx)
        {
            indexes[idx] = -1;
            next[idx] = nullptr;
        }
    }
    ~Node()
    {
        for (Node* n : next)
        {
            if (n)
            {
                delete n;
            }
        }
    }
    
    void init()
    {
        for (int idx = 0; idx < 26; ++idx)
        {
            indexes[idx] = idx + 1;
        }
    }
    
    vector<int> indexes;
    vector<Node*> next;
    
    bool has_next(char c0, char c1)
    {
        int p0 = c0 - 'A';
        int p1 = c1 - 'A';
        if (next[p0])
        {
            return next[p0]->indexes[p1] != -1;
        }
        else
        {
            return false;
        }
    }
    Node* get_next(char ch)
    {
        int p = ch - 'A';
        return next[p];
    }
    int get_index(char ch)
    {
        int p = ch - 'A';
        return indexes[p];
    }
    void add_next(char c0, char c1, int next_idx)
    {
        int p0 = c0 - 'A';
        int p1 = c1 - 'A';
        if (next[p0] == nullptr)
        {
            next[p0] = new Node();
        }
        next[p0]->indexes[p1] = next_idx;
    }
};

/*
[20,15,2,5,15,18,14,15,20,20,15,29,15,18,36,38,18,33,-1]
[20,15,2,5,15,18,14,15,20,27,29,31,36,30,32,34]
*/

int find_longest(Node* node, string msg, int idx, int& len, int& next_index)
{
    int size = msg.size();
    len = 1;
    while (idx + 1 < size)
    {
        const char c0 = msg[idx];
        const char c1 = msg[idx + 1];
        
        if (node->has_next(c0, c1))
        {
            len += 1;
            idx += 1;
            node = node->get_next(c0);
        }
        else
        {
            node->add_next(c0, c1, next_index);
            next_index += 1;
            
            return node->get_index(c0);
        }
    }
    return node->get_index(msg[idx]);
}

int LZW(Node* node, string msg, int& idx, int& next_index)
{
    int len;
    int result = find_longest(node, msg, idx, len, next_index);
    idx += len;
    return result;
}

/*
*/

vector<int> solution(string msg)
{
    
    Node node;
    Node* head = &node;
    head->init();
    
    vector<int> answer;
    
    int idx = 0;
    int len = msg.size();
    int next_index = 27;
    while (idx < len)
    {
        answer.push_back(LZW(head, msg, idx, next_index));
    }
    return answer;
}