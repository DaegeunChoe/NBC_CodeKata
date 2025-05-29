#include <string>
#include <vector>
#include <queue>

#include <iostream>

using namespace std;

// 탐색 정보를 저장하는 구조체
struct FCoord
{
    FCoord() {}
    FCoord(int _x, int _y) : x(_x), y(_y) {}
    bool operator ==(FCoord& Other) const
    {
        return (x == Other.x) && (y == Other.y);
    }
    int x;
    int y;
};

struct FNode
{
    FNode(int _x, int _y, int _m) : Coord(_x, _y), MoveCount(_m) {}
    FCoord Coord;
    int MoveCount;
};

// 맵 출력 함수..
void PrintMap(vector<vector<char>>& Map)
{
    for (int y=0; y<Map.size(); y++)
    {
        for (int x=0; x<Map[y].size(); x++)
        {
            cout << Map[y][x] << ' ';
        }
        cout << '\n';
    }
    cout << "============\n";
}

bool CanMove(vector<vector<char>>& Map, FCoord& Current, int dx, int dy, FCoord& Next)
{
    int my = Map.size();
    int mx = Map[0].size();
    
    if (dx == 1)
    {
        for (int x=Current.x; x<mx; x++)
        {
            if (x == mx-1 || Map[Current.y][x+1] == 'D')
            {
                if (Map[Current.y][x] == '.' || Map[Current.y][x] == 'G')
                {
                    Next.x = x;
                    Next.y = Current.y;
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    else if (dx == -1)
    {
        for (int x=Current.x; x>=0; x--)
        {
            if (x == 0 || Map[Current.y][x-1] == 'D')
            {
                if (Map[Current.y][x] == '.' || Map[Current.y][x] == 'G')
                {
                    Next.x = x;
                    Next.y = Current.y;
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    else if (dy == 1)
    {
        for (int y=Current.y; y<my; y++)
        {
            if (y == my-1 || Map[y+1][Current.x] == 'D')
            {
                if (Map[y][Current.x] == '.' || Map[y][Current.x] == 'G')
                {
                    Next.x = Current.x;
                    Next.y = y;
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    else if (dy == -1)
    {
        for (int y=Current.y; y>=0; y--)
        {
            if (y == 0 || Map[y-1][Current.x] == 'D')
            {
                if (Map[y][Current.x] == '.' || Map[y][Current.x] == 'G')
                {
                    Next.x = Current.x;
                    Next.y = y;
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return false;
}

int solution(vector<string> board)
{
    // 2차원 배열 맵
    vector<vector<char>> Map;
    vector<vector<bool>> Checker;
    FCoord Start, End;
    
    for (int y=0; y<board.size(); y++)
    {
        int x_size = board[y].size();
        Map.emplace_back(x_size, '.');
        Checker.emplace_back(x_size, false);
        
        for (int x=0; x<x_size; x++)
        { 
            char ch = board[y][x];
            Map[y][x] = ch;
            if (ch == 'R')
            {
                Start.x = x;
                Start.y = y;
                Checker[y][x] = true;
            }
            if (ch == 'G')
            {
                End.x = x;
                End.y = y;
            }
        }
    }

    // 시작지점을 큐에 넣고, BFS 시작
    queue<FNode> BFSQueue;
    BFSQueue.emplace(Start.x, Start.y, 0);
    
    // 4방향
    FCoord MoveCoord[4] = {
        FCoord(-1, 0), FCoord(+1, 0), FCoord(0, -1), FCoord(0, +1)
    };
    
    // BFS
    while (BFSQueue.size() > 0)
    {
        FNode Cursor = BFSQueue.front();
        BFSQueue.pop();
        Map[Cursor.Coord.y][Cursor.Coord.x] = Cursor.MoveCount;
        // PrintMap(Map);
        if (Cursor.Coord == End)
        {
            return Cursor.MoveCount;
        }
        
        FCoord Next;
        for (auto& mc : MoveCoord)
        {
            if (CanMove(Map, Cursor.Coord, mc.x, mc.y, Next))
            {
                BFSQueue.emplace(Next.x, Next.y, Cursor.MoveCount + 1);
                // Map[Next.y][Next.x] = '0' + Cursor.MoveCount + 1;
                // cout << "move(" << mc.x << ',' << mc.y << ")\n";
            }
        }
    }
    return -1;
}




