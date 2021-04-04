#include <vector>
#include <unordered_set>
using namespace std;
int makeN(int N, int idx) {
    int res = N;
    for (int i = 1; i < idx; i++)
        res = res * 10 + N;
    return res;
}
int solution(int N, int number) {
    if (N == number) return 1;
    unordered_set<int>DP[9];
    DP[1].insert(N);
    for (int k = 2; k <= 8; k++) {
        for (int i = 1; i < k; i++) {
            int j = k-i;
            for (int a : DP[i]) {
                for (int b : DP[j]) {
                    DP[k].insert(a + b);
                    if (a - b > 0) DP[k].insert(a - b);
                    DP[k].insert(a * b);
                    if (a / b > 0) DP[k].insert(a / b);
                }
            }
        }
        DP[k].insert(makeN(N, k));
        if (DP[k].count(number)) return k;
    }
    return -1;
}
