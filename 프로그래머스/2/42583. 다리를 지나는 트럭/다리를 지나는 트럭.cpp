#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int time;
    int weight;
    Node(int time, int weight) : time(time), weight(weight) {}
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    
    queue<Node> nodes;
    int total_weight = 0;
    int index = 0;
    int len = truck_weights.size();
    
    int time = 1;
    while (index < len) {
        int next_weight = truck_weights[index];
        bool can_add = (nodes.size() < bridge_length) && (total_weight + next_weight <= weight);
        if (can_add) {
            nodes.emplace(time, next_weight);
cout << "[push] truck " << next_weight << " in:" << time << endl;
            index++;
            total_weight += next_weight;
            time += 1;
        }
        else {
            // remove
            Node& last_truck = nodes.front();
            total_weight -= last_truck.weight;
            if (time < (last_truck.time + bridge_length))
                time = (last_truck.time + bridge_length);
cout << "[pop] truck " << last_truck.weight << " in:" << last_truck.time << ", out: " << time << endl;
            nodes.pop();
        }
    }
    
    while (nodes.size() > 0) {
        Node& last_truck = nodes.front();
        if (time < (last_truck.time + bridge_length))
            time = (last_truck.time + bridge_length);
cout << "[flush] last truck " << last_truck.weight << " in:" << last_truck.time << ", out: " << time << endl;
        nodes.pop();
    }     
   
    return time;
}