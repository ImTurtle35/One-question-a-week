#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    const int mod = 1234567;
    vector<long long>dp;
    dp.push_back(1);
    for(int i=1; i <= n ; i++){
        if(i == 1) dp.push_back(1);
		else if (i == 2) dp.push_back(2);
        else dp.push_back((dp[i-1] + dp[i-2]) % mod);
    }
    answer = dp.back() % mod;
    return answer;
}
