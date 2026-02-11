#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

/*
[S -> P] + [P -> A] + [P -> B]
S(P) + A(P) + B(P)
각각의 최소를 구해서 더하면 된다...?
*/

typedef int node_index;
typedef int node_distance;

struct Node
{
public:
    Node()
    {
    }
    Node (node_index index, node_distance dist)
        : index(index), dist(dist)
    {
        
    }
    node_index index = -1;
    node_distance dist = -1;
    
    bool operator < (const Node& right)
    {
        return dist > right.dist; // min heap
    }
};

using namespace std;

void minimum_distance(
    int n, 
    node_index start, 
    vector<map<node_index, node_distance>>& matrix, 
    vector<node_distance>& result)
{
    result.empty();
    for (int idx = 0; idx <= n; ++idx)
    {
        result.push_back(-1);
    }
    
    vector<Node> heap;
    vector<bool> history(n + 1, false);
    
    heap.emplace_back(start, 0);
    
    while (heap.size() > 0)
    {
        pop_heap(heap.begin(), heap.end());
        Node current = heap.back();
        heap.pop_back();
        
        if (history[current.index])
        {
            continue;
        }
        history[current.index] = true;
    
        result[current.index] = current.dist;
        
        // cout << "current: " << current.index << ", result: " << result[current.index] << endl;
        
        for (auto& edge : matrix[current.index])
        {
            node_index to = edge.first;
            node_distance dist = edge.second;
            
            heap.emplace_back(to, dist + current.dist);
            push_heap(heap.begin(), heap.end());
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    vector<map<node_index, node_distance>> dist_matrix(n + 1);
    
    for (vector<int>& fare : fares)
    {
        node_index from = fare[0];
        node_index to = fare[1];
        node_distance dist = fare[2];
        
        dist_matrix[from][to] = dist;
        dist_matrix[to][from] = dist;
    }
    
    // for (int from = 1; from <= n; ++from)
    // {
    //     for (auto& edge : dist_matrix[from])
    //     {
    //         node_index to = edge.first;
    //         node_distance dist = edge.second;
    //         cout << from << " -> " << to << " = " << dist << endl;
    //     }
    // }
    
    vector<node_distance> from_s;
    minimum_distance(n, s, dist_matrix, from_s);

    // vector<node_distance> to_a(n + 1, -1);
    // vector<node_distance> to_b(n + 1, -1);
    
    vector<node_distance> from_a;
    minimum_distance(n, a, dist_matrix, from_a);

    vector<node_distance> from_b;
    minimum_distance(n, b, dist_matrix, from_b);
    
    auto& to_a = from_a;
    auto& to_b = from_b;
    
    // for (int from = 1; from <= n; ++from)
    // {
    //     vector<node_distance> from_i;
    //     minimum_distance(n, from, dist_matrix, from_i);
    //     to_a[from] = from_i[a];
    //     to_b[from] = from_i[b];
    // }
    
    node_distance minimum = to_a[s] + to_b[s];
    for (int mid = 1; mid <= n; ++mid)
    {
        if (from_s[mid] < 0 || to_a[mid] < 0 || to_b[mid] < 0)
        {
            continue;
        }
        
        node_distance sum = from_s[mid] + to_a[mid] + to_b[mid];
        if (minimum > sum)
        {
            minimum = sum;
        }
    }
    
    int answer = minimum;
    return answer;
}

