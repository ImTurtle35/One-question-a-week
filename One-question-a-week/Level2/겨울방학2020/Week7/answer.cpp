#include <string>
#include <vector>

using namespace std;

void dfs (vector<int>numbers,int& ans,int cur, int target, int finish, int sum) {
    if(cur == finish) {
        if(sum == target) ans++;
        return;
    }
    dfs(numbers,ans,cur+1,target,finish,sum+ numbers[cur]);
    dfs(numbers,ans,cur+1,target,finish,sum-numbers[cur]);
    
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers,answer,0,target,numbers.size(),0);
    return answer;
}
