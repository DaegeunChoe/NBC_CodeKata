#include <string>
#include <vector>

using namespace std;

// #include <iostream>

int rotate(vector<vector<int>>& matrix, int rows, int cols, vector<int> query) {
    
    int temp1, temp2, temp3;
    int min = rows * cols + 1;
    
    int r0 = query[0] - 1;
    int c0 = query[1] - 1;
    int r1 = query[2] - 1;
    int c1 = query[3] - 1;
    
    // 윗 변
    temp1 = matrix[r0][c1];
    for (int c = c1; c > c0; c--) {
        matrix[r0][c] = matrix[r0][c-1];
    }
    
    // 오른쪽 변
    temp2 = matrix[r1][c1];
    for (int r = r1; r > r0; r--) {
        matrix[r][c1] = matrix[r-1][c1];
    }
    matrix[r0+1][c1] = temp1;
    
    // 밑 변
    temp3 = matrix[r1][c0];
    for (int c = c0; c < c1; c++) {
        matrix[r1][c] = matrix[r1][c+1];
    }
    matrix[r1][c1-1] = temp2;
    
    // 왼쪽 변
    for (int r = r0; r < r1; r++) {
        matrix[r][c0] = matrix[r+1][c0];
    }
    matrix[r1-1][c0] = temp3;
    
    // 최솟값
    for (int c = c0 ; c <= c1; c++) {
        if (matrix[r0][c] < min) min = matrix[r0][c];
        if (matrix[r1][c] < min) min = matrix[r1][c];
    }
    for (int r = r0 + 1; r < r1; r++) {
        if (matrix[r][c0] < min) min = matrix[r][c0];
        if (matrix[r][c1] < min) min = matrix[r][c1];
    }
    return min;
}



vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    
    // 행렬 만들기
    vector<vector<int>> matrix;
    for (int n=0; n<rows; n++) {
        matrix.emplace_back(columns);
    }
    int i = 1;
    for (int r=0; r<rows; r++) {
        for (int c=0; c<columns; c++) {
            matrix[r][c] = i;
            i += 1;
        }
    }
    
    vector<int> answer;
    for (auto& query : queries) {
        answer.push_back(rotate(matrix, rows, columns, query));
        
        // if (rows <= 7 && columns <= 7) {
        //     for (int r=0; r<rows; r++) {
        //         for (int c=0; c<columns; c++) {
        //             cout << matrix[r][c] << " ";
        //         }
        //         cout << endl;
        //     }
        //     cout << "---" << endl;
        // }
    }
    return answer;
}