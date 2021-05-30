#include <vector>
#include <algorithm>
 
using namespace std;

int n;
int dp[101][101];
void floyd() {
    for(int k{1}; k <= n; k++) {
        for(int i{1}; i <= n; i++) {
            for(int j{1}; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}
 
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    bool graph[101][101];
    for(int i{1}; i <= n; i++) {
        for(int j{1}; j <= n; j++) {
            graph[i][j] = false;
        }
    }
    for(int i{0}; i < results.size(); i++) {
        graph[results[i][0]][results[i][1]] = true;
     }
    for(int k{1}; k <= n; k++) {
        for(int i{1}; i <= n; i++) {
            for(int j{1}; j <= n; j++) {
                if(graph[i][k] && graph[k][j]) {
                    graph[i][j] = true;
                }
            }
        }
    }
    for(int i{1}; i <= n; i++) {
        int count = 0;
        for(int j{1}; j <= n; j++) {
            if(graph[i][j] || graph[j][i]) count++;
        }
        if(count == n-1) answer++;
    }
    return answer;
}
