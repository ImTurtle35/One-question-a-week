#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};
 
int solution(vector<vector<int>> jobs) {
    int answer = 0, cur = 0, time = 0, len = jobs.size();
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    while (cur < len || !pq.empty()) {
        if (cur < len && time >= jobs[cur][0]) {
            pq.push(jobs[cur]);
            cur++;
            continue;
        }
        if (!pq.empty()) {
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else
            time = jobs[cur][0];
    }
    return answer / len;
}
