#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> computers)
{
    vector<bool> history(n, false);
    int count = 0;
    int network_count = 0;
    vector<int> stack;
    vector<int> network(n, -1);

    while (count < n)
    {
        int next_root = -1;
        for (int idx = 0; idx < n; ++idx)
        {
            if (!history[idx])
            {
                next_root = idx;
                break;
            }
        }
        
        network_count += 1;
        
        stack.emplace_back(next_root);
        history[next_root] = true;
        network[next_root] = network_count;
        count += 1;
        
        while (stack.size() > 0)
        {
            int current = stack.back();
            stack.pop_back();
            
            // cout << "dfs: " << current << "(" << network_count << ")" << endl;
            
            for (int next = 0; next < n; ++next)
            {
                if (computers[current][next] != 1)
                {
                    continue;
                }
                if (!history[next])
                {
                    stack.emplace_back(next);
                    history[next] = true;
                    network[next] = network_count;
                    count += 1;
                }
            }
        }
        // cout << "==========\n";
    }
    
    for (int idx = 0; idx < n; ++idx)
    {
        // cout << "idx: " << idx << ", network: " << network[idx] << endl;
    }
    
    int answer = network_count;
    return answer;
}