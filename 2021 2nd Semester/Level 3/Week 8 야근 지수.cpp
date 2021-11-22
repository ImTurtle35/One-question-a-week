#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int>pq;
    for(int i{0}; i < works.size(); i++) {
        pq.push(works[i]);
    }
    for(int i{0}; i < n; i++) {
        int tmp = pq.top();
        if(tmp <= 0) break;
        pq.pop();
        tmp -= 1;
        pq.push(tmp);
    }
    while(!pq.empty()) {
        int tmp = pq.top();
        pq.pop();
        answer += tmp * tmp;
    }
    return answer;
}
