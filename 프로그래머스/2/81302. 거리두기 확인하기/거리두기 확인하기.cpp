#include <string>
#include <vector>
#define ROW 5
#define COL 5
using namespace std;

bool isValid(int r, int c, vector<string>& place) {
    // 맨하탄 거리가 1인 지점은 총 4군데
    if (r-1 >= 0 && place[r-1][c] == 'P') {
        return false;
    }
    if (c-1 >= 0 && place[r][c-1] == 'P') {
        return false;
    }
    if (r+1 < ROW && place[r+1][c] == 'P') {
        return false;
    }
    if (c+1 < COL && place[r][c+1] == 'P') {
        return false;
    }
    
    // 맨하탄 거리가 2인 지점은 총 8군데
    // 직선 방향
    if (r-2 >= 0 && place[r-2][c] == 'P') {
        if (place[r-1][c] != 'X') {
            return false;
        }
    }
    if (c-2 >= 0 && place[r][c-2] == 'P') {
        if (place[r][c-1] != 'X') {
            return false;
        }
    }
    if (c+2 < COL && place[r][c+2] == 'P') {
        if (place[r][c+1] != 'X') {
            return false;
        }
    }
    if (r+2 < ROW && place[r+2][c] == 'P') {
        if (place[r+1][c] != 'X') {
            return false;
        }
    }
    // 대각선 방향
    if (r-1 >= 0 && c-1 >= 0 && place[r-1][c-1] == 'P') {
        if (place[r-1][c] == 'X' && place[r][c-1] == 'X') {
        }
        else {
            return false;
        }
    }
    if (r-1 >= 0 && c+1 < COL && place[r-1][c+1] == 'P') {
        if (place[r-1][c] == 'X' && place[r][c+1] == 'X') {
        }
        else {
            return false;
        }
    }
    if (r+1 < ROW && c-1 >= 0 && place[r+1][c-1] == 'P') {
        if (place[r+1][c] == 'X' && place[r][c-1] == 'X') {
        }
        else {
            return false;
        }
    }
    if (r+1 < ROW && c+1 < COL && place[r+1][c+1] == 'P') {
        if (place[r+1][c] == 'X' && place[r][c+1] == 'X') {
        }
        else {
            return false;
        }
    }
    
    return true;
}

bool checker(vector<string>& place) {
    
    for (int r=0; r<ROW; r++) {
        for (int c=0; c<COL; c++) {
            if (place[r][c] == 'P') {
                if (!isValid(r, c, place)) {
                    return false;
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (auto& place : places) {
        if (checker(place)) {
            answer.push_back(1);
        }
        else {
            answer.push_back(0);
        }
    }
    return answer;
}