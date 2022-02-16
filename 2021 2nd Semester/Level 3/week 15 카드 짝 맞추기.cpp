#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct pos {
    int r,c,cnt;
};
int curr, curc;
int mover[4] = {-1,1,0,0};
int movec[4] = {0,0,-1,1};
bool checknum[7] = {false,};
vector<int>comb;
vector<pos>card[7];
vector<pos>path;
vector<vector<pos>>paths;
int save[4][4];

int bfs(pos target) {
    queue<pos>que;
    bool visit[4][4] = {false,};
    que.push({curr,curc,0});
    visit[curr][curc] = true;
    while(!que.empty()){
        int r = que.front().r;
        int c = que.front().c;
        int cnt = que.front().cnt;
        que.pop();
        if(r == target.r && c == target.c) {
            curr = r; curc = c;
            save[r][c] = 0;
            return cnt+1;
        }

        for(int i{0}; i < 4; i++) {
            int nxtr = r + mover[i];
            int nxtc = c + movec[i];
            if(nxtr < 0 || nxtr > 3 || nxtc < 0 || nxtc > 3) continue;
            if(visit[nxtr][nxtc]) continue;
            que.push({nxtr,nxtc,cnt+1});
            visit[nxtr][nxtc] = true;
        }

        for(int i{0}; i < 4; i++) {
            int nxtr = r; int nxtc = c;
            while(true) {
                nxtr += mover[i];
                nxtc += movec[i];
                if(nxtr < 0 || nxtr > 3 || nxtc < 0 || nxtc > 3) {
                    nxtr -= mover[i];
                    nxtc -= movec[i];
                    break;
                }
                if(save[nxtr][nxtc]) break;              
            }
            if(visit[nxtr][nxtc]) continue;
            que.push({nxtr,nxtc,cnt+1});
            visit[nxtr][nxtc] = true;
        }
    }
}

void make_path(int idx) {
    if(idx == comb.size()) {
        paths.push_back(path);
        return;
    }
    int num = comb[idx];
    path.push_back(card[num][0]);
    path.push_back(card[num][1]);
    make_path(idx+1);
    path.pop_back();
    path.pop_back();
    path.push_back(card[num][1]);
    path.push_back(card[num][0]);
    make_path(idx+1);
    path.pop_back();
    path.pop_back();
}


int solution(vector<vector<int>> board, int r, int c) {
    int answer = 1e9;
    for(int i{0}; i < 4; i++) {
        for(int j{0}; j < 4; j++) {
            if(board[i][j] != 0){
                checknum[board[i][j]] = true;
                card[board[i][j]].push_back({i,j,});
            }
        }
    }
    for(int i{1}; i <= 6; i++) {
        if(checknum[i])
            comb.push_back(i);
    }
    do{
        make_path(0);
        for(int k{0}; k < paths.size(); k++) {
            int cnt = 0;
            curr = r; curc = c;
            for(int i{0}; i < 4; i++) {
                for(int j{0}; j < 4; j++)
                    save[i][j] = board[i][j];
            }
            for(int i{0}; i < paths[k].size(); i++) {
                cnt += bfs(paths[k][i]);
            }
            answer = min(answer, cnt);
        }
        paths.clear();
    }while(next_permutation(comb.begin(),comb.end()));
    

    return answer;
}
