#include <string>
#include <vector>

using namespace std;

// Need: 필요한 빈병 수
// Get: 얻을 수 있는 콜라 수
// Have: 내가 가지고 있는 빈병 수
int solution(int Need, int Get, int Have)
{
    int Answer = 0;
    
    // 내가 가지고 있는 빈 병의 수가, Need 보다 부족하면 끝난다.
    while (Have >= Need)
    {
        // 빈 병으로 새 콜라를 받는다. 빈 병이 줄어든다.
        int NewDrink = (Have / Need) * Get;
        Have = Have % Need;
        
        // 마신다. 새 빈 병이 생긴다.
        Answer += NewDrink;
        Have += NewDrink;
    }
    return Answer;
}