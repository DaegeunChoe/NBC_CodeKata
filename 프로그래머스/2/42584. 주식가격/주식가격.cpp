#include <string>
#include <vector>

using namespace std;

struct Node
{
public:
    Node(int time, int price): time(time), price(price)
    {
    }
    int time;
    int price;
};


vector<int> solution(vector<int> prices) {
    
    vector<Node> stack;
    vector<int> answer(prices.size(), 0);
    
    for (int time = 0; time < prices.size(); ++time)
    {
        int price = prices[time];
        if (stack.size() <= 0)
        {
            stack.emplace_back(time, price);
        }
        else
        {
            while(stack.size() > 0)
            {
                Node pop = stack.back();
                if (price < pop.price)
                {
                    stack.pop_back();
                    answer[pop.time] = time - pop.time;
                }
                else
                {
                    break;
                }
            }
            stack.emplace_back(time, price);
        }
    }
    
    while(stack.size() > 0)
    {
        Node pop = stack.back();
        stack.pop_back();
        answer[pop.time] = prices.size() - pop.time - 1;
    }
    
    
    return answer;
}