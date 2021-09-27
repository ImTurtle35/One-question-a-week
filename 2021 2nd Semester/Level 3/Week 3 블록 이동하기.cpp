#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct robot{
    int x,y,dir,count;
};
const int dx[2] = {1,0};
const int dy[2] = {0,1};
const int mx[4] = {-1, 0 ,1, 0};
const int my[4] = {0, -1, 0, 1};
bool visit[101][101][2];

bool checkbound(int x1, int x2, int y1, int y2, vector<vector<int>> board) {
    int b_size = board.size();
    if(x1 < 0 || x1 >= b_size) return false;
    if(x2 < 0 || x2 >= b_size) return false;
    if(y1 < 0 || y1 >= b_size) return false;
    if(y2 < 0 || y2 >= b_size) return false;
    if(board[y1][x1]) return false;
    if(board[y2][x2]) return false;
    return true;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int b_size = board.size();
    queue<robot>que;
    que.push({0,0,0,0});
    visit[0][0][0] = true;
    while(!que.empty()) {
        int x1 = que.front().x, y1 = que.front().y;
        int dir = que.front().dir;
        int count = que.front().count;
        int x2 = x1 + dx[dir], y2 = y1 + dy[dir];
        que.pop();
        if((x1 == b_size-1 && y1 == b_size -1) ||
           (x2 == b_size-1 && y2 == b_size -1)) {
            return count;  
        }
        // move
        for(int i{0}; i < 4; i++) {
            int nx1 = x1 + mx[i], ny1 = y1 + my[i];
            int nx2 = x2 + mx[i], ny2 = y2 + my[i];
            if(checkbound(nx1,nx2,ny1,ny2,board)) {
                if(visit[ny1][nx1][dir]) continue;
                que.push({nx1,ny1,dir,count+1});
                visit[ny1][nx1][dir] = true;
            }
        }
        // 가로이면
        if(dir == 0) {
            if(y1 > 0 && !board[y1-1][x1] && !board[y1-1][x2]) {
                if(!visit[y1-1][x1][1]) {
                    que.push({x1,y1-1,1,count+1});
                    visit[y1-1][x1][1] = true;
                }
                if(!visit[y1-1][x2][1]) {
                    que.push({x2,y1-1,1,count+1});
                    visit[y1-1][x2][1] = true;
                }
            }
            if(y1 < b_size-1 && !board[y1+1][x1] && !board[y1+1][x2]) {
                if(!visit[y1][x1][1]) {
                    que.push({x1,y1,1,count+1});
                    visit[y1][x1][1] = true;
                }
                if(!visit[y1][x2][1]) {
                    que.push({x2,y1,1,count+1});
                    visit[y1][x2][1] = true;
                }
            }
        }
        // 세로이면
        else if (dir == 1){
            if(x1 > 0 && !board[y1][x1-1] && !board[y2][x1-1]) {
                if(!visit[y1][x1-1][0]) {
                    que.push({x1-1,y1,0,count+1});
                    visit[y1][x1-1][0] = true;
                }
                if(!visit[y2][x1-1][0]) {
                    que.push({x1-1,y2,0,count+1});
                    visit[y2][x1-1][0] = true;
                }
            }
            if(x1 < b_size-1 && !board[y1][x1+1] && !board[y2][x1+1]) {
                if(!visit[y1][x1][0]) {
                    que.push({x1,y1,0,count+1});
                    visit[y1][x1][0] = true;
                }
                if(!visit[y2][x1][0]) {
                    que.push({x1,y2,0,count+1});
                    visit[y2][x1][0] = true;
                }
            }
        }
    }

    return answer;
}
