#include <string>
#include <vector>

using namespace std;

void dfs(int n, int index, vector<vector<int>>&computers, vector<bool>&visit) {
    for(int i{0}; i < n; i++) {
        if(!visit[i] && computers[index][i]) {
            visit[i] = true;
            dfs(n,i,computers,visit);
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
            dfs(n,i,computers,visit);
        }
    }
    return answer;
}
