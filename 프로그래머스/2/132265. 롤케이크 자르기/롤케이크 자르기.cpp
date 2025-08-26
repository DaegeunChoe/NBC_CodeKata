#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> toppings) {
    
    map<short, int> topping_dict_0;
    map<short, int> topping_dict_1;
    
    for (short topping : toppings) {
        if (topping_dict_0.find(topping) == topping_dict_0.end()) {
            topping_dict_0[topping] = 0;
        }
        topping_dict_0[topping] += 1;
    }
    
    int answer = 0;
    int len = toppings.size();
    for (int index = 0; index < len; index++) {
        short topping = toppings[index];
        
        topping_dict_0[topping] -= 1;
        if (topping_dict_0[topping] <= 0) {
            topping_dict_0.erase(topping);
        }
        if (topping_dict_1.find(topping) == topping_dict_1.end()) {
            topping_dict_1[topping] = 0;
        }
        topping_dict_1[topping] += 1;
        
        if (topping_dict_0.size() == topping_dict_1.size()) {
            answer += 1;
        }
        
        // cout << "topping_dict_0.size(): " << topping_dict_0.size()
        //      << ", topping_dict_1.size(): " << topping_dict_1.size() << endl;
        // for (const auto& pair : topping_dict_0) {
        //     cout << pair.first << ": " << pair.second << endl;
        // }
    }
    return answer;
}