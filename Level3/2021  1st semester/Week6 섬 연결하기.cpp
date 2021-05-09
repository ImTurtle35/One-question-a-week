#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct DS{
    vector<int>par;
    DS(int a) {
        par.resize(a+1,-1);
    }
    int f(int v) {
        if(par[v] == -1) return v;
        return par[v] = f(par[v]);
    }
    void u(int x, int y) {
        x = f(x), y = f(y);
        if(x==y) return;
        par[x] = y;
    }
};

bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int cnt = 1, idx = 0;
    sort(costs.begin(),costs.end(),cmp);
    DS ds(n);
    while(cnt < n) {
        if(ds.f(costs[idx][0]) != ds.f(costs[idx][1])) {
            ds.u(costs[idx][0],costs[idx][1]);
            answer += costs[idx][2];
            cnt++;
        }
        idx++;
    }
    return answer;
}
