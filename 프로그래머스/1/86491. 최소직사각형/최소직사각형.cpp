#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// struct Node{
//     Node(int w, int h) : w(w), h(h) {} 
//     int w;
//     int h;
//     bool operator <(const Node& right) {
//         return h < right.h;
//     }
// };

#include <iostream>

int solution(vector<vector<int>> sizes) {
    
    int max_w = -1;
    int max_h = -1;
    
    for (auto& size : sizes) {
        int w = size[0];
        int h = size[1];
        if (max_w == -1) {
            max_w = w;
        }
        if (max_h == -1) {
            max_h = h;
        }
        
        if (max_h < h && max_w < w) {
            max_w = w;
            max_h = h;
        }
        else if (max_h < h) {
            int case1 = max_w * h;
            int temp_max_w = max_w > h ? max_w : h;
            int temp_max_h = max_h > w ? max_h : w;
            int case2 = temp_max_w * temp_max_h;
            if (case1 < case2) {
                max_h = h;
            }
            else {
                max_w = temp_max_w;
                max_h = temp_max_h;
            }
        }
        else if (max_w < w) {
            int case1 = max_h * w;
            int temp_max_w = max_w > h ? max_w : h;
            int temp_max_h = max_h > w ? max_h : w; 
            int case2 = temp_max_w * temp_max_h;
            if (case1 < case2) {
                max_w = w;
            }
            else {
                max_w = temp_max_w;
                max_h = temp_max_h;
            } 
        }    
        // cout << "max: " << max_w << ", " << max_h << endl;
    }
    
    int answer = 0;
    return max_w * max_h;
}