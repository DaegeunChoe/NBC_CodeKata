#include <string>
#include <vector>
#include <iostream>

using namespace std;

class FCombination
{
public:
    FCombination(int N, int C): N(N), C(C), Indexes(C, 0)
    {
        isStart = false;
    }
    
    bool Next()
    {
        if (!isStart)
        {
            isStart = true;
            for (int i = 0; i < C; ++i)
            {
                Indexes[i] = i;
            }
            return true;
        }
        else
        {
            for (int j = 1; j <= C; ++j)
            {
                if (Indexes[C-j] + j < N)
                {
                    Indexes[C-j] += 1;
                    
                    for (int m = 0; m < j - 1; m++)
                    {
                        Indexes[C-j+m+1] = Indexes[C-j+m] + 1;
                    }
                    return true;
                }
            }
            return false;
        }
    }
    
    vector<int> Indexes;
    bool isStart;
    int N;
    int C;
};

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    
    vector<vector<bool>> check;
    
    int row_size = beginning.size();
    int col_size = 0;
    int same_check = 0;
    for (int row = 0; row < row_size; ++row)
    {
        col_size = beginning[row].size();
        check.emplace_back(col_size, false);
        for (int col = 0; col < col_size; ++col)
        {
            check[row][col] = beginning[row][col] == target[row][col];
            if (check[row][col])
            {
                same_check += 1;
            }
        }
    }
    if (same_check == row_size * col_size)
    {
        return 0;
    }
    // for (auto RRR : check){for (auto CCC: RRR){cout << CCC;}cout << endl;}
    
    int answer = -1;
    
    for (int i = 0; i <= row_size; ++i)
    {
        FCombination Comb(row_size, i);
        
        while (Comb.Next())
        {
            vector<vector<bool>> copy;
            for (int row = 0; row < row_size; ++row)
            {
                copy.emplace_back(col_size, false);
                for (int col = 0; col < col_size; ++col)
                {
                    copy[row][col] = check[row][col];
                }
            }
            
            for (int r : Comb.Indexes)
            {
                for (int col = 0; col < col_size; ++col)
                {
                    if (copy[r][col])
                    {
                        copy[r][col] = false;
                    }
                    else
                    {
                        copy[r][col] = true;
                    }
                }
            }
            
            int remains = 0;
            for (auto _r : copy)
            {
                for (auto _el : _r)
                {
                    if (!_el)
                    {
                        remains += 1;
                    }
                }
            }
            
            
            for (int j = 0; j < col_size; j++)
            {
                FCombination Comb2(col_size, j);
                
                while (Comb2.Next())
                {
                    bool valid = true;
                    int jc = 0;
                    for (int c : Comb2.Indexes)
                    {
                        for (int row = 0 ; row < row_size; ++row)
                        {
                            if (copy[row][c])
                            {
                                valid = false;
                            }
                            else
                            {
                                jc += 1;
                            }
                        }
                    }
                    if (valid && jc == remains)
                    {
                        cout << "유효한 케이스: " << (i + j) << endl;
                        if (answer == -1)
                        {
                            answer = (i + j);
                        }
                        else 
                        {
                            answer = answer < (i + j) ? answer : (i + j);
                        }
                        // for (auto RRR : copy){for (auto CCC: RRR){cout << CCC;}cout << endl;}
                    }
                }
            }
        }
    }
       
    return answer;
}
