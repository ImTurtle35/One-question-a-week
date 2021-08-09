#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{
    int answer = 0;
    int dist[202][202];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dist[i][j] = 1e9;
        }
    }
    for(int i = 0; i < fares.size(); i++) {
        dist[fares[i][0]][fares[i][1]] = fares[i][2];
        dist[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    for(int i = 1; i <= n; i++) dist[i][i] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j || i == k || k == j) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    answer = dist[s][a] + dist[s][b];
    for (int i = 1; i <= n; i++) {
        if (dist[s][i] != 1e9 && dist[i][a] != 1e9 && dist[i][b] != 1e9) {
            answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
        }
    }
    return answer;
}
