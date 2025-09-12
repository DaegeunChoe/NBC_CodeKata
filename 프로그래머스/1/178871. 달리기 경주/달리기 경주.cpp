#include <string>
#include <vector>
#include <map>

using namespace std;

struct Node
{
    Node(string inname)
    {
        name = inname;
        prev = nullptr;
        next = nullptr;
    }
    
    void Add(string newname)
    {
        Node* newnode = new Node(newname);
        next = newnode;
        newnode->prev = this;
    }
    
    void Overtaken()
    {
        if (prev == nullptr)
        {
            return;
        }
        
        Node* front = prev;
        Node* back = next;
    
        if (front) front->next = back;
        if (back) back->prev = front;
        
        Node* ahead = front->prev;
        
        if (ahead)
        {
            ahead->next = this;
        }
        this->next = front;
        front->prev = this;
        this->prev = ahead;
    }
    
    string name;
    Node* prev;
    Node* next;
};


vector<string> solution(vector<string> players, vector<string> callings) {
    
    Node head("DummyHead");
    Node* cursor = &head;
    map<string, Node*> nodemap;
    for (const string& player : players)
    {
        cursor->Add(player);
        cursor = cursor->next;
        nodemap[player] = cursor;
    }
    
    for (const string& calling : callings)
    {
        Node* target = nodemap[calling];
        target->Overtaken();
    }
    
    vector<string> answer;
    Node* temp;
    cursor = head.next;
    while (cursor)
    {
        answer.push_back(cursor->name);
        temp = cursor;
        cursor = cursor->next;
        delete temp;
    }
    return answer;
}