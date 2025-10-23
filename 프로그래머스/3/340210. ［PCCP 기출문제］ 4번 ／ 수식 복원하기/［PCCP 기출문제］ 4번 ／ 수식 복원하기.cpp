#include <string>
#include <vector>
#include <iostream>

using namespace std;

class FExpression
{
public:
    FExpression(string& In)
    {
        size_t plus = In.find('+');
        size_t minus = In.find('-');
        size_t equal = In.find("=");
        if (plus != string::npos)
        {
            A = In.substr(0, plus-1);
            B = In.substr(plus+2, equal-plus-3);
            Op = '+';
        }
        else // (minus != string::npos)
        {
            A = In.substr(0, minus-1);
            B = In.substr(minus+2, equal-minus-3);
            Op = '-';
        }
        C = In.substr(equal+2);
        
        if (C[0] == 'X')
        {
            Unknown = true;
        }
        else
        {
            Unknown = false;
        }
        cout << A << ", " << B << ", " << C << endl;
    }
    
    string A;
    string B;
    string C;
    char Op;
    bool Unknown;
};

class FSolver
{
public:
    
    void FindMaxNumber(vector<FExpression>& Expressions)
    {
        for (auto Exp : Expressions)
        {
            int result = FindMaxNumber(Exp) + 1;
            Min = result > Min ? result : Min;
        }
    }
    int FindMaxNumber(FExpression& Exp)
    {
        int max = 0;
        for (const char& c : Exp.A)
        {
            max = c - '0' > max ? c - '0' : max;
        }
        for (const char& c : Exp.B)
        {
            max = c - '0' > max ? c - '0' : max;
        }
        if (!Exp.Unknown)
        {
            for (const char& c : Exp.C)
            {
                max = c - '0' > max ? c - '0' : max;
            }
        }
        return max;   
    }
    
    void Check(vector<FExpression>& Expressions)
    {
        int NewMax = Min;
        int NewMin = Max;
        for (int n = Max; n >= Min; n--)
        {
            bool isOK = true;
            for (auto Exp : Expressions)
            {
                if (!Exp.Unknown)
                {
                    if (!Try(Exp, n))
                    {
                        isOK = false;
                        break;
                    }
                }
            }
            
            if (isOK)
            {
                cout << "진법 " << n << "은 유효함!\n";
                NewMax = n > NewMax ? n : NewMax;
                NewMin = n < NewMin ? n : NewMin;
            }
            else
            {
                cout << "진법 " << n << "은 유효하지 않음\n";
            }
        }
        Max = NewMax;
        Min = NewMin;
       
        if (Min == Max)
        {
             cout << "진법은 " << Min << "\n";
        }
        else
        {
             cout << "진법: " << Min << " - " << Max << "\n";
        }
    }
    
    void MakeAnswer(vector<FExpression>& Expressions, vector<string>& answer)
    {
        for (auto Exp : Expressions)
        {
            if (!Exp.Unknown)
            {
                continue;
            }
            
            string ans;
            ans += Exp.A;
            ans += Exp.Op == '+' ? " + " : " - ";
            ans += Exp.B;
            ans += " = ";
            
            if (Min == Max)
            {
                if (Exp.Op == '+')
                {
                    Exp.C = Add(Exp, Min);
                }
                else // if (Exp.Op == '-')
                {
                    Exp.C = Minus(Exp, Min);
                }
            
            }
            else
            {
                if (Exp.Op == '+')
                {
                    bool checker = false;
                    string temp = Add(Exp, Min, &checker);
                    if (!checker)
                    {
                        Exp.C = temp;
                    }
                    else
                    {
                        Exp.C = "?";
                    }
                }
                else // if (Exp.Op == '-')
                {
                    bool checker = false;
                    string temp = Minus(Exp, Min, &checker);
                    if (!checker)
                    {
                        Exp.C = temp;
                    }
                    else
                    {
                        Exp.C = "?";
                    }
                }
            }
            
            ans += Exp.C;
            
            answer.push_back(ans);
        }
    }
    
    string Add(FExpression& Exp, int n, bool* changed = nullptr)
    {
        int sizeA = Exp.A.size();
        int sizeB = Exp.B.size();

        int zero_A = Exp.A[sizeA-1] - '0';
        int zero_B = Exp.B[sizeB-1] - '0';
        int zero_Sum = zero_A + zero_B;
        int One_Sum = 0;

        if (zero_Sum >= n)
        {
            zero_Sum = zero_Sum - n;
            One_Sum += 1;
            
            if (changed) *changed = true;
        }

        int one_A = sizeA < 2 ? 0 : Exp.A[sizeA-2] - '0';
        int one_B = sizeB < 2 ? 0 : Exp.B[sizeB-2] - '0';
        int Two_Sum = 0;
        One_Sum += (one_A + one_B);
        
        if (One_Sum >= n)
        {
            One_Sum = One_Sum - n;
            Two_Sum = 1;
            
            if (changed) *changed = true;
        }

        int make = Two_Sum * 100 + One_Sum * 10 + zero_Sum;
        string result = to_string(make);
        return result;
    }
    
    string Minus(FExpression& Exp, int n, bool* changed = nullptr)
    {
        int sizeA = Exp.A.size();
        int sizeB = Exp.B.size();

        int zero_A = Exp.A[sizeA-1] - '0';
        int zero_B = Exp.B[sizeB-1] - '0';
        int zero_Sum = zero_A - zero_B;
        int One_Sum = 0;

        if (zero_Sum < 0)
        {
            zero_Sum = n + zero_Sum;
            One_Sum -= 1;
            
            if (changed) *changed = true;
        }

        int one_A = sizeA < 2 ? 0 : Exp.A[sizeA-2] - '0';
        int one_B = sizeB < 2 ? 0 : Exp.B[sizeB-2] - '0';
        One_Sum += (one_A - one_B);

        int make =  One_Sum * 10 + zero_Sum;
        string result = to_string(make);
        return result;
    }
    
    bool Try(FExpression& Exp, int n)
    {   
        string result;
        if (Exp.Op == '+')
        {
            cout << "PLUS> ";
            result = Add(Exp, n);
        }
        else // if (Exp.Op == '-')
        {
            cout << "MINUS> ";
            result = Minus(Exp, n);
        }
        
        cout << result << " vs " << Exp.C << ", " << n << endl;
        if (result.compare(Exp.C) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    int Min = 2;
    int Max = 9;
};


vector<string> solution(vector<string> expressions) {
    
    FSolver Solver;
    vector<FExpression> Expressions;
    
    for (auto e : expressions)
    {
        Expressions.emplace_back(e);
    }
    
    Solver.FindMaxNumber(Expressions);
    Solver.Check(Expressions);
    
    vector<string> answer;
    Solver.MakeAnswer(Expressions, answer);
    return answer;
}