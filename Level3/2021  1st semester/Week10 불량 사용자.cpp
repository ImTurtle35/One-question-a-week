#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<int>s;
bool visit[8];

void dfs(vector<string>&user_id, vector<string>&banned_id, int idx) {
    if(idx == banned_id.size()) {
        int ans = 0;
        for(int i{0}; i < user_id.size(); i++) {
            if(visit[i]) {
                ans |= (1 << i);
            }
        }
        s.insert(ans);
    }
    else {
        string bi = banned_id[idx];
        for(int i{0}; i < user_id.size(); i++){
            if(visit[i]) continue;
            string ui = user_id[i];
            if(ui.size() != bi.size()) continue;
            bool ban=true;
            for(int k=0; k < ui.size(); k++){
               if(bi[k]=='*') continue;
               if(bi[k]!=ui[k]){
                   ban=false;
                   break;
               }
            }
            if(ban){
                visit[i]=true;
                dfs(user_id, banned_id, idx+1);
                visit[i]=false;
            }
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    dfs(user_id,banned_id,0);
    answer = s.size();
    return answer;
}
