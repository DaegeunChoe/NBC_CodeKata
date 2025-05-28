#include <string>
#include <vector>
#include <stack>

using namespace std;

bool Checker(int Begin, int End, int Length, const char* Input)
{
    stack<char> MyStack;

    if (End < Begin)
    {
        End += Length;
    }
    while (Begin <= End)
    {
        char Cursor = Input[(Begin % Length)];
        char Top;
        switch (Cursor)
        {
        // 여는 괄호
        case '[':
        case '{':
        case '(':
            MyStack.push(Cursor);
            break;
        // 닫는 괄호
        case ']':
            Top = MyStack.top();
            MyStack.pop();
            if (Top != '[')
            {
                return false;
            }
            break;
        case '}':
            Top = MyStack.top();
            MyStack.pop();
            if (Top != '{')
            {
                return false;
            }
            break;
        case ')':
            Top = MyStack.top();
            MyStack.pop();
            if (Top != '(')
            {
                return false;
            }
            break;
        }
        Begin += 1;
    }
    return MyStack.empty() ? true : false;
}

int solution(string s)
{
    const char* Input = s.c_str();
    int Length = s.size();
     int answer = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (Checker(i, (i+Length-1) % Length, Length, Input))
        {
            answer += 1;
        }
    }    
    return answer;
}