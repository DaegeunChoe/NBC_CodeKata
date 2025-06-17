#include <string>
#include <vector>
#include <algorithm>
// #include <iostream>

using namespace std;

struct Node {
    Node(int r, int c) : r(r), c(c) {}
    int r;
    int c;
};

// '섬' 구하기
void bfs(
    int r, int c, int row, int col,
    vector<string>& maps, 
    vector<vector<int>>& group_map) {
    
    vector<Node> queue;
    queue.emplace_back(r, c);
    
    while (queue.size() > 0) {
        Node current = queue.back();
        queue.pop_back();
        
        if (current.r > 0 && maps[current.r-1][current.c] != 'X' && group_map[current.r-1][current.c] == 0) {
            queue.emplace_back(current.r-1, current.c);
            group_map[current.r-1][current.c] = group_map[current.r][current.c];
        }
        if (current.r < row-1 && maps[current.r+1][current.c] != 'X' && group_map[current.r+1][current.c] == 0) {
            queue.emplace_back(current.r+1, current.c);
            group_map[current.r+1][current.c] = group_map[current.r][current.c];
        }
        if (current.c > 0 && maps[current.r][current.c-1] != 'X' && group_map[current.r][current.c-1] == 0) {
            queue.emplace_back(current.r, current.c-1);
            group_map[current.r][current.c-1] = group_map[current.r][current.c];
        }
        if (current.c < col-1 && maps[current.r][current.c+1] != 'X' && group_map[current.r][current.c+1] == 0) {
            queue.emplace_back(current.r, current.c+1);
            group_map[current.r][current.c+1] = group_map[current.r][current.c];
        }
    }
}

int find_island(int row, int col, vector<string>& maps, vector<vector<int>>& group_map) {
    
    int group_count = 0;
    for (int r=0; r<row; r++) {
        for (int c=0; c<col; c++) {
            if (maps[r][c] != 'X' && group_map[r][c] == 0) {
                group_count += 1;
                group_map[r][c] = group_count;
                bfs(r, c, row, col, maps, group_map);
            }
        }
    }
    
    // for (int r=0; r<row; r++) {
    //     for (int c=0; c<col; c++) {
    //         cout << group_map[r][c] << ", ";
    //     }
    //     cout << endl;
    // }
    return group_count;
}

vector<int> solution(vector<string> maps) {

    int row = maps.size();
    int col = maps[0].size();
    
    vector<vector<int>> group_map;
    for (int r=0; r<row; r++) {
        group_map.emplace_back(col, 0);
    }
    
    int count = find_island(row, col, maps, group_map);
    if (count == 0) {
        vector<int> answer;
        answer.push_back(-1);
        return answer;
    }
    else
    {
        vector<int> answer(count, 0);
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (group_map[r][c] != 0) {
                    answer[group_map[r][c]-1] += (maps[r][c] - '0');
                }
            }
        }
        sort(answer.begin(), answer.end());
        return answer;
    }
    
}