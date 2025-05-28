#include <string>
#include <vector>

using namespace std;

vector<vector<int>> Transpose(vector<vector<int>> Mat)
{
    vector<vector<int>> Ret;
    int _row = Mat[0].size();
    int _col = Mat.size();
    
    for (int r=0; r<_row; r++)
    {
        Ret.emplace_back(_col, 0);
        for (int c=0; c<_col; c++)
        {
            Ret[r][c] = Mat[c][r];
        }
    }
    return Ret;
}

int Dot(vector<int> A, vector<int> B)
{
    int Sum = 0;
    for (int i=0; i<A.size(); i++)
    {
        Sum += A[i] * B[i];
    }
    return Sum;
}


vector<vector<int>> solution(vector<vector<int>> Mat1, vector<vector<int>> _Mat2)
{
    vector<vector<int>> Answer;
    
    vector<vector<int>> Mat2 = Transpose(_Mat2);
    int _row = Mat1.size();
    int _col = Mat2.size();
    
    for (int r=0; r<_row; r++)
    {
        Answer.emplace_back(_col, 0);
        for (int c=0; c<_col; c++)
        {
            Answer[r][c] = Dot(Mat1[r], Mat2[c]);
        }
    }
    return Answer;
}















