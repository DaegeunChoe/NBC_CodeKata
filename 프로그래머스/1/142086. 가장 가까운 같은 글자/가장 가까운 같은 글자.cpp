#include <string>
#include <vector>

using namespace std;

vector<int> solution(string Query) {
    
    vector<int> Answer;
    Answer.reserve(Query.size());
    const char* List = Query.c_str();
    
    // 각 알파벳이 언제 나타났는지 기록하는 배열
    // -1은 나타난 적이 없는 것
    vector<short> Hitsory(26, -1);
    
    // 순회
    for (int i = 0; i < Query.size(); i++)
    {
        int Alphabet = List[i] - 'a';
        if (Hitsory[Alphabet] == -1)
        {
            Answer.push_back(-1);
        }
        else
        {
            Answer.push_back(i - Hitsory[Alphabet]);
        }
        Hitsory[Alphabet] = i;
    }
    
    return Answer;
}