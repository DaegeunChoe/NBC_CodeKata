#include <string>
#include <vector>

using namespace std;

#include <iostream>

bool check(char board[][3], char target)
{
    // 행 검사
    for (int r = 0; r < 3; r++)
    {
        if (board[r][0] == target && board[r][1] == target && board[r][2] == target)
        {
            return true;
        }
    }
    // 열 검사
    for (int c = 0; c < 3; c++)
    {
        if (board[0][c] == target && board[1][c] == target && board[2][c] == target)
        {
            return true;
        }
    }
    // 대각선 검사
    if (board[0][0] == target && board[1][1] == target && board[2][2] == target)
    {
        return true;
    }
    if (board[0][2] == target && board[1][1] == target && board[2][0] == target)
    {
        return true;
    }
    return false;
}

int solution(vector<string> input)
{
    char board[3][3] = {0};
    int countO = 0;
    int countX = 0;
    for (int r = 0; r < 3; r++)
    {
        const char* arr = input[r].c_str();
        for (int c = 0; c < 3; c++)
        {
            board[r][c] = arr[c];
            if (arr[c] == 'X') countX++;
            else if (arr[c] == 'O') countO++;
        }
    }
    
    // 개수 검사. 
    // 허용되는 경우는 선공==후공과 선공-1==후공 두 경우 뿐
    if (countO == countX || countO-1 == countX)
    {
        bool isOWin = check(board, 'O');
        bool isXWin = check(board, 'X');
        // case: 선공의 승리로 끝났는데, 후공이 게임을 진행한 경우
        if (isOWin && countO == countX)
        {
            return 0;
        }
        // case: 후공의 승리로 끝났는데, 선공이 게임을 진행한 경우
        else if (isXWin && countO-1 == countX)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        // case: 개수가 맞지 않는 경우
        return 0;
    }
}