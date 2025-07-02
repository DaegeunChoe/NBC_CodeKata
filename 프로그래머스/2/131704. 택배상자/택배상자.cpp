#include <string>
#include <vector>
#include <iostream>

using namespace std;

void print_belt(vector<int>& belt) {
    for (int n=belt.size()-1; n>=0; n--) {
        cout << belt[n] << ", ";
    }
    cout << endl;
}

int solution(vector<int> order) {
    
    vector<int> index(order.size());
    vector<int> main;
    vector<int> sub;
    
    for (int n=0; n<order.size(); n++) {
        index[order[n]-1] = n+1;
    }
    
    for (int n=index.size()-1; n >= 0; n--) {
        main.push_back(index[n]);
    }
    
    int target = 1;
    while (true) {
        
        // cout << "current target: " << target << endl;
        // cout << "main: "; print_belt(main);
        // cout << "sub: "; print_belt(sub);
        // cout << "===" << endl;

        // 보조 컨테이너 확인
        while (sub.size() > 0) {
            if (sub.back() == target) {
                sub.pop_back();
                target += 1;
            }
            else {
                break;
            }
        }
        
        // 메인 컨테이너 확인
        while (main.size() > 0) {
            if (main.back() == target) {
                break;
            }
            int temp = main.back();
            sub.push_back(temp);
            main.pop_back();
        }
        if (main.size() > 0 && main.back() == target) {
            main.pop_back();
            target += 1;
        }
        else {
            break;
        }
    }
    
    return target - 1;
}


