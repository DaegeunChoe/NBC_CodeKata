#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

// 탐색 노드
struct Node
{
    Node(int _time, int _power, int _temperature, int _aircon, bool _on) {
        time = _time;
        power = _power;
        temperature = _temperature;
        aircon = _aircon;
        on = _on;
    }
    Node(const Node& other) { // 복사 생성자
        time = other.time;
        power = other.power;
        temperature = other.temperature;
        aircon = other.aircon;
        on = other.on;
    }
    
    int power; // 지금까지 소모한 전력
    int time; // 경과 시간(분)
    int temperature; // 현재 온도
    int aircon; // 목표 온도
    bool on; // 전원 여부
    
    bool operator < (Node& right) const
    {
        // power가 작아야 한다.
        return power > right.power;
    }
    
    static void Push(vector<Node>& myHeap, int, int, int, int, bool);
    static Node Pop(vector<Node>& myHeap);
    
    void print();
};

void Node::print()
{
    cout << time << ", " << power << ", " << temperature;
    if (on)
        cout << ", on to " << aircon;
    else
        cout << ", off";
    cout << "\n";
}

void Node::Push(vector<Node>& myHeap, int time, int power, int temperature, int aircon, bool on)
{
    myHeap.emplace_back(time, power, temperature, aircon, on);
    push_heap(myHeap.begin(), myHeap.end());
}

Node Node::Pop(vector<Node>& myHeap)
{
    pop_heap(myHeap.begin(), myHeap.end());
    Node _t = myHeap.back();
    myHeap.pop_back();
    return _t;
}

int Dist(int a, int b)
{
    return a > b ? a - b : b - a;
}
int Min(int a, int b)
{
    return a < b ? a : b;
}

int TemShift(int tem)
{
    return tem + 10; // [-10,40] 을 [0, 50] 으로 옮김
}

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard)
{
    // 승객이 탑승하기 까지 남아있는 시간을 계산
    int time_size = onboard.size();
    vector<int> remainTime(time_size, -1);
    int last_onboard = -1;
    for (int n=time_size-1; n >=0; n--)
    {
        if (onboard[n] == 1)
        {
            last_onboard = n;
        }
        if (last_onboard != -1)
        {
            remainTime[n] = last_onboard - n;
        }
    }
    
    // 히스토리
    vector<vector<int>> min_costs;
    for (int n=0; n<time_size + 1; n++)
    {
        min_costs.emplace_back(40-(-10)+1, -1);
    }
    
    int answer = -1;
    
    vector<Node> myHeap;
    Node::Push(myHeap, -1, 0, temperature, 0, false);
    while (myHeap.size() > 0)
    {
        Node current = Node::Pop(myHeap);
        // current.print();
        if (current.time >= time_size)
        {
            // current.print();
            if (answer == -1 || current.power < answer)
            {
                answer = current.power;
            }
            continue;
        }
        
        // 다음 온도 계산
        int next_time = current.time + 1;
        int next_power = current.power;
        int next_temperature = current.temperature;
        if (current.on)
        {
            next_temperature += 
                (current.aircon > current.temperature) ? +1 :
                (current.aircon < current.temperature) ? -1 : 0;
            
            next_power += (current.aircon == current.temperature) ? b : a;
        }
        else
        {
            next_temperature += 
                (temperature > current.temperature) ? +1 :
                (temperature < current.temperature) ? -1 : 0;
        }
        
        // 조건을 만족하지 못하는 경우의 수를 제거
        if (onboard[next_time] == 1 && !(t1 <= next_temperature && next_temperature <= t2))
        {
            continue;
        }
        
        int min_cost_value = min_costs[next_time][TemShift(next_temperature)];
        // 에어컨 off
        {
            if ( min_cost_value == -1 || min_cost_value > next_power)
            {
                Node::Push(myHeap, next_time, next_power, next_temperature, 0, false);
                min_costs[next_time][TemShift(next_temperature)] = next_power;
            }
        }
        // 에어컨 on
        {
            if ( min_cost_value == -1 || min_cost_value > next_power)
            {
                Node::Push(myHeap, next_time, next_power, next_temperature, t1, true);
                Node::Push(myHeap, next_time, next_power, next_temperature, t2, true);
                Node::Push(myHeap, next_time, next_power, next_temperature, next_temperature, true);
                min_costs[next_time][TemShift(next_temperature)] = next_power;
            }
        }
    }
    return answer;
}








