#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct FNode
{
    int Type = -1; // 0은 양, 1은 늑대
    int left = -1;
    int right = -1;
    FNode* Left = nullptr;
    FNode* Right = nullptr;
};

struct FDPSNode
{
    FDPSNode(int size, FNode& Node): Next(size, false), OrgNext(size, false)
    {
        SetNext(Node);
    }
    
    FDPSNode(int size, int S, int W, FDPSNode& Before, int MyIndex, FNode& Node): Next(size, false), OrgNext(size, false)
    {
        Sheep = S;
        Woolf = W;
        for (int i=0; i<Next.size(); i++) Next[i] = Before.OrgNext[i];
        for (int i=0; i<Next.size(); i++) OrgNext[i] = Before.OrgNext[i];
        SetNext(Node);
        Next[MyIndex] = false;
        OrgNext[MyIndex] = false;
    }
    
    void SetNext(FNode& Node)
    {
        if (Node.Left)
        {
            Next[Node.left] = true;
            OrgNext[Node.left] = true;
        }
        if (Node.Right)
        {
            Next[Node.right] = true;
            OrgNext[Node.right] = true;
        }
    }
    
    void Info()
    {
        cout << "Sheep: " << Sheep << ", ";
        cout << "Woolf: " << Woolf << ", ";
        for (bool b : Next) cout << (b ? 'O' : 'X') << ' ';
        cout << ", Index: " << Index << endl;
    }
    
    int Sheep = 0; // 현재 양 개수
    int Woolf = 0; // 현재 늑대 개수
    int Index = 0; // 현재 탐색 index
    vector<bool> Next; // 접근 가능한 노드 번호
    vector<bool> OrgNext; // 접근 가능한 노드 번호 원본
};

int solution(vector<int> info, vector<vector<int>> edges) {
    
    vector<FNode> Nodes(info.size());
    for (int i=0; i < info.size(); i++)
    {
        Nodes[i].Type = info[i];
    }
    for (vector<int> edge : edges)
    {
        int from = edge[0];
        int to = edge[1];
        FNode& From = Nodes[from];
        FNode& To = Nodes[to];
        if (From.Left == nullptr)
        {
            From.left = to;
            From.Left = &To;
        }
        else
        {
            From.right = to;
            From.Right = &To;
        }
    }
    
    int answer = 0;
    FNode& Root = Nodes[0];
    
    // DFS
    int N = Nodes.size();
    vector<FDPSNode> Stack;
    Stack.emplace_back(N, Root);
    Stack[0].Sheep += 1;
    
    while (Stack.size() > 0)
    {
        FDPSNode& Back = Stack.back();
        
        while (Back.Index < N)
        {
            if (Back.Next[Back.Index])
            {
                Back.Next[Back.Index] = false;
                
                FNode& Next = Nodes[Back.Index];
                
                if (Next.Type == 1 && Next.Left == nullptr)
                {
                    break;
                }
                
                int NewSheep = Back.Sheep;
                int NewWoolf = Back.Woolf;
                
                if (Next.Type == 0)
                {
                    NewSheep += 1;
                }
                else
                {
                    NewWoolf += 1;
                }
                if (NewWoolf >= NewSheep)
                {
                    NewSheep = 0;
                }
                if (NewSheep != 0)
                {
                    Stack.emplace_back(N, NewSheep, NewWoolf, Back, Back.Index, Next);
                }
                break;
            }
            Back.Index += 1;
        }
        if (Back.Index >= N)
        {
            answer = Back.Sheep > answer ? Back.Sheep : answer;
            Stack.pop_back();
        }
    }
    
    return answer;
}



