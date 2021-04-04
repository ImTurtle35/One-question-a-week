#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int N, int number, int count, int res, int& ans) {
    if (count > 8) return;
    if (res == number) {
        ans = min(ans, count);
        return;
    }
    int tmp = 0;
    for (int i = 0; i + count < 9 ; i++) {
        tmp = tmp * 10 + N;
        dfs(N, number, count + 1 + i, res + tmp,ans);
        dfs(N, number, count + 1 + i, res - tmp,ans);
        dfs(N, number, count + 1 + i, res * tmp,ans);
        dfs(N, number, count + 1 + i, res / tmp,ans);
    }
}
 
int solution(int N, int number) {
    int ans = 1e9;
    dfs(N, number, 0, 0, ans);
    if (ans > 8) return -1;
    return ans;
}
