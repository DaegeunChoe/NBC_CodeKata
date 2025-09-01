#include <string>
#include <vector>

#include <iostream>

using namespace std;

bool CanCompress(vector<vector<int>>& arr, int size, int target, int row, int col)
{
    if (size == 1)
    {
        return arr[row][col] == target;
    }
    else
    {
        for (int r = 0; r < size; r++)
        {
            for (int c = 0; c < size; c++)
            {
                if (arr[row + r][col + c] != target)
                {
                    return false;
                }
            }
        }
        return true;
    }
}

bool CanCompressZero(vector<vector<int>>& arr,int size, int row, int col)
{
    return CanCompress(arr, size, 0, row, col);
}

bool CanCompressOne(vector<vector<int>>& arr, int size, int row, int col)
{
    return CanCompress(arr, size, 1, row, col);
}

void Solver(vector<vector<int>>& arr, int size, int row, int col, int* CountZero, int* CountOne)
{
    if (CanCompressZero(arr, size, row, col))
    {
        *CountZero += 1;
    }
    else if (CanCompressOne(arr, size, row, col))
    {
        *CountOne += 1;
    }
    else
    {
        int half = size / 2;
        Solver(arr, half, row,        col,        CountZero, CountOne);
        Solver(arr, half, row + half, col,        CountZero, CountOne);
        Solver(arr, half, row,        col + half, CountZero, CountOne);
        Solver(arr, half, row + half, col + half, CountZero, CountOne);
    }
}


vector<int> solution(vector<vector<int>> arr) {
    int zero = 0;
    int one = 0;
    Solver(arr, arr.size(), 0, 0, &zero, &one);
    vector<int> answer;
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}