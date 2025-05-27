#include <string>
#include <vector>

using namespace std;

int solution(string Input)
{
    const char* Query = Input.c_str();
    int Length = Input.size();
    
    int Cursor = 0;
    char FirstChar;
    int FirstCount;
    int OtherCount = 0;
    int Output = 0;
    
    bool bIsFirst = true;
    while (Cursor < Length)
    {
        if (bIsFirst)
        {
            bIsFirst = false;
            FirstChar = Query[Cursor];
            FirstCount = 1;
            OtherCount = 0;
            Cursor++;
            continue;
        }
        
        if (Query[Cursor] == FirstChar)
        {
            FirstCount++;
        }
        else
        {
            OtherCount++;
        }
        
        if (FirstCount == OtherCount)
        {
            bIsFirst = true;
            Output++;
        }
        Cursor++;
    }
    
    if (!bIsFirst)
    {
        Output++;
    }
    
    return Output;
}