#include <string>
#include <vector>
#include <map>

using namespace std;

map<string,int>mp;
int parent[10001];
int profit[10001];

void checkprofit(int idx, int m) {
    if(idx == -1) return;
    if(m == 0) return;
    int forparent = m/10;
    m -= forparent;
    profit[idx] += m;
    checkprofit(parent[idx], forparent);
}

vector<int> solution(vector<string> enroll, vector<string> referral,
                        vector<string> seller, vector<int> amount) {
    vector<int> answer;
    for(int i{0}; i < enroll.size(); i++) {
        mp[enroll[i]] = i;
    }
    for(int i{0}; i < referral.size(); i++) {
        if(referral[i] == "-") parent[i] = -1;
        else parent[i] = mp[referral[i]];
    }
    for(int i{0}; i < seller.size() ; i++) {
        checkprofit(mp[seller[i]],amount[i] * 100);
    }
    for(int i{0}; i < enroll.size() ; i++) {
        answer.push_back(profit[i]);
    }
    return answer;
}
