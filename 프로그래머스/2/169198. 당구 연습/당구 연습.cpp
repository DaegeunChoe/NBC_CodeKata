#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    
    for (vector<int>& ball : balls) {
        
        int min = -1;
        int x = ball[0];
        int y = ball[1];
        cout << "(x, y): " << x << "," << y << "\n";
        
        // 변 쿠션
        int xs[] = {x, -x, 2*m-x,     x};
        int ys[] = {-y, y,     y, 2*n-y};
        int xl[] = {-1, 0, m, -1};
        int yl[] = {0, -1, -1, n};
        for (int i=0; i<4; i++) {
            // 경로검사
            if (startY == y && xl[i] != -1) {
                if (xl[i] == 0) {
                    if (x < startX) {
                        continue;
                    }
                }
                else {
                    if (x > startX) {
                        continue;
                    }
                }
            }
            if (startX == x && yl[i] != -1) {
                if (yl[i] == 0) {
                    if (y < startY) {
                        continue;
                    }
                }
                else {
                    if (y > startY) {
                        continue;
                    }
                }
            }
            int dx = xs[i] - startX;
            int dy = ys[i] - startY;
            int dist = (dx * dx) + (dy * dy);
     
            cout << "[" << i << "] dist: " << dist << "\n";
            
            if (min == -1) min = dist;
            else min = min < dist ? min : dist;
        }
        
        // 꼭지점 쿠션
        int xe[] = {-x, 2*m-x,    -x, 2*m-x};
        int ye[] = {-y,    -y, 2*n-y, 2*n-y};
        int xp[] = {0, m, 0, m};
        int yp[] = {0, 0, n, n};
        for (int i=0; i<4; i++) {
            int ax0 = startX - xp[i];
            int ax1 = x - xp[i];
            int ay0 = startY - yp[i];
            int ay1 = y - yp[i];
            // 같은 직선상에 있나? ax0 : ay0 ==? ax1 : ay1
            if (ay0 * ax1 != ax0 * ay1) {
                continue;
            }
            // 경로검사
            if (false) {
                
            }
            int dx = xe[i] - startX;
            int dy = ye[i] - startY;
            int dist = (dx * dx) + (dy * dy);
     
            cout << "[" << i << "] dist: " << dist << "\n";
            
            if (min == -1) min = dist;
            else min = min < dist ? min : dist;
        }
        
        answer.push_back(min);
    }
    return answer;
}