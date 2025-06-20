#include <string>
#include <vector>

using namespace std;

// 바이너리 서치
int binary_search(int left, int right, vector<long long>& f, long long target) {
    if (left > right) {
        return -1;
    }
    int middle = (left + right) / 2;
    if (f[middle] == target) {
        return middle;
    }
    else if (f[middle] < target) {
        return binary_search(middle + 1, right, f, target);
    }
    else { // f[middle] > target
        return binary_search(left, middle-1, f, target);
    }
}

int inv(long long y, vector<long long>& f) {
    return binary_search(0, f.size()-1, f, y);
}

vector<int> solution(vector<int> sequence, int k) {
    
    // sum array
    vector<long long> f;
    f.push_back(0);
    for (int& n : sequence) {
        f.push_back(f.back() + n);
    }
    
    // 모든 방법 찾기
    int min = -1;
    int ma = 0, mb = 0;
    for (int a=0; a<sequence.size(); a++) {
        int fa = f[a];
        int fb = k + fa;
        int b = inv(fb, f);
        if (b != -1) {
            if (min == -1 || min > (b-a)) {
                ma = a;
                mb = b;
                min = (b-a);
            }
        }
    }
    vector<int> answer;
    answer.push_back(ma);
    answer.push_back(mb-1);
    return answer;
}