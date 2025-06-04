#include <string>
#include <vector>

using namespace std;

// 퀸 두거나 빼기
inline int abs(int x)
{
    return ((x>0)?(x):(-x));
} 
void Quene(vector<vector<int>>& board, int px, int py, int n, bool place=true)
{
    int value = place ? 1 : -1;
    for (int y=0; y<n; y++)
    {
        for (int x=0; x<n; x++)
        {
            if (y == py) board[y][x] += value;
            else if (x == px) board[y][x] += value;
            else if ( abs(px-x) == abs(py-y) ) board[y][x] += value;
        }
    }
}

// 재귀 함수
void Solve(vector<vector<int>>& board, int y, int n, int& a)
{
    
    for (int x=0; x<n; x++)
    {
        // cout << "curren Y: " << y;
        // cout << ", curren X: " << x << "\n";
        if (board[y][x] <= 0)
        {
            Quene(board, x, y, n);
            if (y == n-1)
            {
                a += 1;
            }
            else
            {
                Solve(board, y+1, n, a);
            }
            Quene(board, x, y, n, false);
        }
    }
}

// 부르트포스
int solution(int n)
{
    int answer = 0;
    
    // 체스판
    vector<vector<int>> board;
    for (int y=0; y<n; y++)
    {
        board.emplace_back(n, 0);
    }
    Solve(board, 0, n, answer);
    return answer;
}