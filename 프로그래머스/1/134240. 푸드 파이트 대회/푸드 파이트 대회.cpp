#include <string>
#include <vector>

using namespace std;

string solution(vector<int> FoodInput) 
{
    vector<char> Print;
    int FoodLength = FoodInput.size();
    for (int i = 1; i < FoodLength; i++)
    {
        for (int n = 0; n < FoodInput[i] / 2; n++)
        {
            Print.push_back(i + '0');
        }
    }
    Print.push_back('0');
    for (int i = FoodLength - 1; i >= 1; i--)
    {
        for (int n = 0; n < FoodInput[i] / 2; n++)
        {
            Print.push_back(i + '0');
        }
    }
    
    string Answer(Print.begin(), Print.end());
    return Answer;
}