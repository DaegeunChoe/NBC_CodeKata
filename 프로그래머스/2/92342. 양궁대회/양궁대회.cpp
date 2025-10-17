#include <string>
#include <vector>
#include <iostream>

using namespace std;

class FCombination
{
public:
    FCombination(int n, int c): n(n), c(c), Indexs(c, 0)
    {
        for (int i=0; i<c; ++i)
        {
            Indexs[i] = i;
        }
        end = false;
    }
    
    void Next()
    {
        int last = c-1;
        while ((last >= 0) && (Indexs[last]  >= (n - c + last)))
        {
            last -= 1;
        }

        if (last < 0)
        {
            end = true;
            return;
        }

        Indexs[last] += 1;
        for (int l=last + 1; l < c; l++)
        {
             Indexs[l] =  Indexs[l-1] + 1;
        }
    }
    
    void Print()
    {
        for (int n : Indexs)
        {
            cout << n+1 << ", ";
        }
        cout << endl;
    }
    
    int n;
    int c;
    bool end;
    vector<int> Indexs;
};

vector<int> solution(int n, vector<int> info) {
    
    
    vector<int> answer;
    int diff = -1;

    for (int M = 1; M <= 10; ++M)
    {
        FCombination Combination(11, M);
        // cout << "Combination(11," << M << ")\n";
        while (!Combination.end)
        {        
            // 라이언이 이 점수 조합을 획득할 수 있는가?
            int total = 0;
            vector<int> Lion(11, 0);
            for (int i : Combination.Indexs)
            {
                total += info[i] + 1;
                Lion[i] = info[i] + 1;
            }

            if (total > n)
            {
                // 불가능한 점수 조합
                Combination.Next();
                continue;
            }
            else // total <= n
            {   
                int scoreLion = 0;
                int scoreApeech = 0;

                for (int a = 0; a < 11; ++a)
                {
                    if (info[a] == 0 && Lion[a] == 0)
                    {
                        continue;
                    }
                    
                    if (info[a] >= Lion[a])
                    {
                        scoreApeech += 10 - a;
                    }
                    else
                    {
                        scoreLion += 10 - a;
                    }
                }
                if (scoreLion > scoreApeech)
                {
                    int newdiff = scoreLion - scoreApeech;
                    if (diff == -1 || newdiff >= diff)
                    {
                        diff = newdiff;
                        cout << "갱신 " << scoreLion << " vs " << scoreApeech << '\n';
                        answer.clear();
                        for (int l : Lion)
                        {
                            answer.push_back(l);
                        }
                        
                        if (total < n)
                        {
                            answer[10] = n - total;
                        }
                    }
                }
                Combination.Next();
                continue;
            }
        }
    }
    
    if (answer.size() == 0)
    {
        answer.push_back(-1);
    }
    
    return answer;
}


