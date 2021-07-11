#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct position {
  int x, y, dir, cost;  
};
const int xmove[4] = {-1,0,1,0};
const int ymove[4] = {0,-1,0,1};
int dp[25][25];

int solution(vector<vector<int>> board) {
    int answer = 0;
    int board_size = board.size() - 1;
    queue<position>que;
    // 0:left, 1:up, 2:right, 3:down
    if(board[0][1] == 0) que.push({1,0,2,100});
    if(board[1][0] == 0) que.push({0,1,3,100});
    while(!que.empty()) {
        int cur_x = que.front().x, cur_y = que.front().y,
        cur_dir = que.front().dir, cur_cost = que.front().cost;
        que.pop();
        for(int i{0}; i < 4; i++) {
            if(cur_dir - i == 2 || cur_dir - i == -2) continue;
            int nxt_x = cur_x + xmove[i],nxt_y = cur_y + ymove[i],
            nxt_cost = cur_cost;
            if(nxt_x < 0 || nxt_x > board_size || nxt_y < 0 ||
            nxt_y > board_size || board[nxt_y][nxt_x] == 1) continue;
            if(i == cur_dir)
                nxt_cost += 100;
            else nxt_cost += 600;
            if(dp[nxt_y][nxt_x] == 0 || dp[nxt_y][nxt_x] >= nxt_cost){
                que.push({nxt_x,nxt_y,i,nxt_cost});
                dp[nxt_y][nxt_x] = nxt_cost;
            }
        } 
    }
    answer = dp[board_size][board_size];
    return answer;
}
