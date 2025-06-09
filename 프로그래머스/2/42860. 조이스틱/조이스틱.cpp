#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
public:
    string Name;
    int Cursor;
    int Movement;
    
    Node(int n) : Name(n, 'A') {}
    bool operator <(const Node& Right) { return Movement > Right.Movement; }
};

class Solver
{
public:
    void Push();
    Node Pop();
    Node& Top();
    bool Empty() { return Queue.size() == 0; }
    int Len;
    Solver(int len) : Len(len) {}
protected:
    vector<Node> Queue;
};

void Solver::Push()
{
    Queue.emplace_back(Len);
    push_heap(Queue.begin(), Queue.end());
}

Node Solver::Pop()
{
    pop_heap(Queue.begin(), Queue.end());
    auto top = Queue.back();
    Queue.pop_back();
    return top;
}

Node& Solver::Top()
{
    return Queue.back();
}

int ABS(int x)
{
    return x >= 0 ? x : -x;
}

#include <iostream>

int solution(string Name)
{
    int len = Name.size();
    Solver MySolver(len);
    
    vector<int> DistanceArray(len, 0);
    const char* Array = Name.c_str();
    for (int n=0; n<len; n++)
    {
        int from = 'A' - 'A';
        int to = Array[n] - 'A';
        int up = ABS(to - from);
        int down = ABS((from + ('Z' - 'A') + 1) - to);
        DistanceArray[n] = up > down ? down : up;
    }
    
    // 다양한 시작점이 있을 수 있다...
    int A = -1;
    for (int n=0; n<len; n++)
    {
        MySolver.Push();
        Node& First = MySolver.Top();
        First.Cursor = n;
        First.Movement = (n<=(len/2))?(n):(len-n);
        int answer = First.Movement;
        
        while (!MySolver.Empty())
        {
            Node Current = MySolver.Pop();

            if (Current.Name == Name)
            {
                break;
            }
            answer += DistanceArray[Current.Cursor];
            Current.Name[Current.Cursor] = Name[Current.Cursor];

            // 정방향
            int forward = -1;
            for (int n=1; n<len; n++)
            {
                int index = (Current.Cursor + n) % len;
                if (Current.Name[index] != Name[index])
                {
                    forward = n;
                    break;
                }
            }

            // 역방향
            int backward = -1;
            for (int n=1; n<len; n++)
            {
                int index = (Current.Cursor - n + len) % len;
                if (Current.Name[index] != Name[index])
                {
                    backward = n;
                    break;
                }
            }

            // 이동할 필요가 없다면 끝.
            if (forward == -1 || backward == -1)
            {
                break;
            }

            // 가까운 방향으로 이동
            if (forward <= backward)
            {
                MySolver.Push();
                Node& Next = MySolver.Top();
                Next.Cursor = (Current.Cursor + forward) % len;
                Next.Name = Current.Name;
                answer += forward;
            }
            else
            {
                MySolver.Push();
                Node& Next = MySolver.Top();
                Next.Cursor = (Current.Cursor - backward + len) % len;
                Next.Name = Current.Name;
                answer += backward;
            }
        }
        // cout << "answer: " << answer << "\n";
        if (A == -1) A = answer;
        A = A > answer ? answer : A;
    }
    return A;
}