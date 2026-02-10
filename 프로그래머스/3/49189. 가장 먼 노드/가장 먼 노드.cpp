#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <iostream>

using namespace std;

typedef int node_index;

struct Node
{
public:
    Node(node_index index) : index(index)
    {
        distance = -1;
    }
    void Connect(node_index to)
    {
        nexts.insert(to);
    }
    
    node_index index;
    set<node_index> nexts;
    int distance;
};

void BFS(int n, vector<Node>& graph)
{
    list<node_index> queue;
    map<node_index, bool> history;
    
    for (int idx = 1; idx <= n; ++idx)
    {
        history[idx] = false;
    }
    history[1] = true;
    
    queue.emplace_back(1);
    graph[1].distance = 0;
    
    while (queue.size() > 0)
    {
        node_index current = queue.front();
        queue.pop_front();
        
        cout << "bfs: " << current << endl;
        
        for (node_index next : graph[current].nexts)
        {
            if (!history[next])
            {
                history[next] = true;
                queue.emplace_back(next);
                graph[next].distance = graph[current].distance + 1;
            }
        }
    }
}

int solution(int n, vector<vector<int>> edges)
{
    vector<Node> graph;
    for (int idx = 0; idx <= n; ++idx)
    {
        graph.emplace_back(idx);
    }
    
    for (const vector<int>& edge : edges)
    {
        node_index from = edge[0];
        node_index to = edge[1];
        graph[from].Connect(to);
        graph[to].Connect(from);
    }
    
    BFS(n, graph);
    
    int answer = 0;
    int max_distance = 0;
    
    for (int idx = 1; idx <= n; ++idx)
    {
        Node& item = graph[idx];
        if (item.distance <= 0)
        {
            continue;
        }
        if (max_distance == item.distance)
        {
            answer += 1;
        }
        else if (max_distance < item.distance)
        {
            max_distance = item.distance;
            answer = 1;
        }
    }
    
   
    return answer;
}

