#include <string>
#include <vector>
#include <iostream>

// 모든 코드에서 범위 체크 생략

using namespace std;


bool Checker(const char* Query, const char* Target, int Len)
{
    for (int i = 0; i < Len; i++)
    {
        if (Query[i] != Target[i])
        {
            return false;
        }
    }
    return true;
}


char Solver(const char* Query, const int InIndex, int& OutIndex)
{
    // 그냥 숫자일 경우
    if ('0' <= Query[InIndex] && Query[InIndex] <= '9')
    {
        // 그대로 리턴
        OutIndex += 1;
        return Query[InIndex];
    }
    
    // 그렇지 않을 경우, 문자열 검사를 실행
    if (Checker(Query + InIndex, "zero", 4)) {
        OutIndex += 4;
        return '0';
    }
    else if (Checker(Query + InIndex, "one", 3)) {
        OutIndex += 3;
        return '1';
    }
    else if (Checker(Query + InIndex, "two", 3)) {
        OutIndex += 3;
        return '2';
    }
    else if (Checker(Query + InIndex, "three", 5)) {
        OutIndex += 5;
        return '3';
    }
    else if (Checker(Query + InIndex, "four", 4)) {
        OutIndex += 4;
        return '4';
    }
    else if (Checker(Query + InIndex, "five", 4)) {
        OutIndex += 4;
        return '5';
    }
    else if (Checker(Query + InIndex, "six", 3)) {
        OutIndex += 3;
        return '6';
    }
    else if (Checker(Query + InIndex, "seven", 5)) {
        OutIndex += 5;
        return '7';
    }
    else if (Checker(Query + InIndex, "eight", 5)) {
        OutIndex += 5;
        return '8';
    }
    else if (Checker(Query + InIndex, "nine", 4)) {
        OutIndex += 4;
        return '9';
    }
}
    
int solution(string Input)
{
    const char* Question = Input.c_str();
    int Cursor = 0;
    int Answer = 0;
    while (Cursor < Input.length())
    {
        Answer *= 10;
        Answer += Solver(Question, Cursor, Cursor) - '0';
    }
    return Answer;
}