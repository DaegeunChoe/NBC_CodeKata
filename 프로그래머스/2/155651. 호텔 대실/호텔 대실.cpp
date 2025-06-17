#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

static int to_int(const char* src) {
    int a0 = (src[0] - '0') * 10 * 60;
    int a1 = (src[1] - '0') * 60;
    int a2 = (src[3] - '0') * 10;
    int a3 = (src[4] - '0');
    return (a0 + a1) + (a2 + a3);
}

struct Node {
    Node(vector<string>& input) {
        start_time = to_int(input[0].c_str());
        end_time = to_int(input[1].c_str());
    }
    
    bool operator <(const Node& right) const {
        return start_time < right.start_time;
    }
    
    // 단위는 '분'
    int start_time; 
    int end_time;
};

int solution(vector<vector<string>> book_times) {
    
    // 예약 정보
    vector<Node> book_list;
    for (auto& book: book_times) {
        book_list.emplace_back(book);
    }
    sort(book_list.begin(), book_list.end());
    
    // 방 정보
    vector<vector<Node*>> room_list;
    room_list.emplace_back();
    
    for (auto& book : book_list) {
        
        // 들어갈 수 있는 빈 방이 있는가?
        bool flag = false;
        for (int n=0; n<room_list.size(); n++) {
            if (room_list[n].size() == 0) {
                room_list[n].push_back(&book);
                flag = true;
                break;
            }
            else {
                Node* last = room_list[n].back();
                if (last->end_time + 10 <= book.start_time) {
                    room_list[n].push_back(&book);
                    flag = true;
                    break;
                }
            }
        }
        // 새 방을 만든다.
        if (!flag) {
            room_list.emplace_back();
            room_list.back().push_back(&book);
        }
    }
    
    // 방 정보 출력
    // for (int n=0; n<room_list.size(); n++) {
    //     cout << n << " room: ";
    //     for (Node* b : room_list[n]) {
    //         cout << b->start_time << "->" << b->end_time << ", ";
    //     }
    //     cout << endl;
    // }
    
    return room_list.size();
}