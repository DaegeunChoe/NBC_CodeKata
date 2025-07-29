#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    
    int rows = wallpaper.size();
    int cols = wallpaper[0].size();
    int lux = cols;
    int luy = rows;
    int rdx = 0;
    int rdy = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (wallpaper[r][c] == '#') {
                lux = lux < c ? lux : c;
                luy = luy < r ? luy : r;
                rdx = rdx > c ? rdx : c;
                rdy = rdy > r ? rdy : r;
            }
        }
    }
    vector<int> answer;
    answer.push_back(luy);
    answer.push_back(lux);
    answer.push_back(rdy + 1);
    answer.push_back(rdx + 1);
    return answer;
}