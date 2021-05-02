#include <string.h>
#include <vector>

using namespace std;

int dp[101][101];

int findAns(int x, int y) {
    int &ret = dp[y][x];
    if(ret != -1) return ret;
    int res = 0;
    if(x > 1) res += findAns(x-1,y);
    if(y > 1) res += findAns(x,y-1);
    return ret = res % 1000000007;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    memset(dp,-1,sizeof(dp));
    dp[1][1] = 1;
    for(int i{0}; i < puddles.size(); i++)
        dp[puddles[i][1]][puddles[i][0]] = 0;
    answer = findAns(m,n);
    return answer;
}
