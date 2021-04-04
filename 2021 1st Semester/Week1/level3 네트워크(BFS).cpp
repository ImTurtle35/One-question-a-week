#include <string>
#include <vector>
#include <queue>

using namespace std;

void bfs(int n,int index, vector<vector<int>>&computers, vector<bool>&visit) {
    queue<int>que;
    que.push(index);
    while(!que.empty()) {
        int cur = que.front();
        que.pop();
        for(int i{0}; i < n; i++) {
            if(!visit[i] && computers[cur][i]) {
                visit[i] = true;
                que.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>>computers) {
    int answer = 0;
    vector<bool>visit;
    visit.resize(n+1,false);
    for(int i{0}; i < n; i++) {
        if(!visit[i]) {
            answer++;
            visit[i] = true;
            bfs(n,i,computers,visit);
        }
    }
    return answer;
}
