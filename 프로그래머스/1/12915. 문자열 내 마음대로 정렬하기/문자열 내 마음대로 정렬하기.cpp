#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class FMyClass
{
public:
    FMyClass(string OriginalString, int SortIndex);
    bool operator <(const FMyClass &Ref) const;
    string GetString() const { return String; }
private:
    string String;
    int Index;
};

FMyClass::FMyClass(string OriginalString, int SortIndex)
{
    String = OriginalString;
    Index = SortIndex;
}
bool FMyClass::operator <(const FMyClass &Ref) const
{
    char A = String[Index];
    char B = Ref.String[Ref.Index];  
    if (A == B)
    {
        return String < Ref.String;
    }
    else
    {
        return  A < B;
    }
}

vector<string> solution(vector<string> Strings, int N)
{
    vector<FMyClass> TempVector;
    for (auto &Element : Strings)
    {
        TempVector.emplace_back(Element, N);
    }
    std::sort(TempVector.begin(), TempVector.end());
    
    vector<string> Answer;
    for (auto &Element : TempVector)
    {
        Answer.push_back(Element.GetString());
    }
    return Answer;
}