#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    Node(int number, int count): number(number), count(count) {}
    int number;
    int count;
};

int solution(int x, int y, int n) {
    int answer = -1;
    
    queue<Node> search_space;
    search_space.emplace(y, 0);
    
    while (search_space.size() > 0) {
        Node node = search_space.front();
        search_space.pop();
        if (node.number == x) {
            answer = node.count;
            break;
        }
        else if (node.number < x) {
            continue;
        }
        else {
            int next_count = node.count + 1;
            search_space.emplace(node.number - n, next_count);
            if (node.number % 2 == 0) {
                search_space.emplace(node.number / 2, next_count);
            }
            if (node.number % 3 == 0) {
                search_space.emplace(node.number / 3, next_count);
            }
        }
    }
    return answer;
}