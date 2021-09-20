#include <string>
#include <vector>

using namespace std;
struct pos
{
    int x, y;
};
int check[102][102];
vector<pos> alpha[28];

void init(int m, int n, vector<string> board)
{
    for(int i{0}; i < 28; i++) {
        alpha[i].clear();
    }
    for (int i{0}; i < m; i++)
    {
        for (int j{0}; j < n; j++)
        {
            check[i][j] = board[i][j];
            if (check[i][j] >= 'A' && check[i][j] <= 'Z')
            {
                pos p = {j, i};
                alpha[check[i][j] - 'A'].push_back(p);
            }
        }
    }
}

bool checkroute(int c) {
    // 편의상 x축을 행으로 y축을 열로
    int sx = alpha[c][0].x, sy = alpha[c][0].y;
    int ex = alpha[c][1].x, ey = alpha[c][1].y;
    int cx = sx, cy = sy;
    bool route_check = true;
    // 1) x축 따라 끝까지 이동하고 y축을 따라 도착점을 찾는 경로
    while(route_check && cx != ex) {
        if(check[cy][cx] != c + 'A' && check[cy][cx] != '.') {
            route_check = false;
            break;
        } 
        if(cx < ex) cx++;
        else cx--;
    }
    while(route_check && cy != ey) {
        if(check[cy][cx] != c + 'A' && check[cy][cx] != '.') {
            route_check = false;
            break;
        }
        if(cy < ey) cy++;
        else cy--;
    }
    if(check[cy][cx] == c + 'A') return true;
    route_check = true;
    cx = sx, cy = sy;
    // 2) y축 따라 끝까지 이동하고 x축을 따라 도착점을 찾는 경로
    while(route_check && cy != ey) {
        if(check[cy][cx] != c + 'A' && check[cy][cx] != '.') {
            route_check = false;
            break;
        }
        if(cy < ey) cy++;
        else cy--;
    }
    while(route_check && cx != ex) {
        if(check[cy][cx] != c + 'A' && check[cy][cx] != '.') {
            route_check = false;
            break;
        }
        if(cx < ex) cx++;
        else cx--;
    }
    if(check[cy][cx] == c + 'A') return true;
    else return false;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
    string answer = "";
    init(m,n,board);
    bool possible = true;
    while(possible){
        possible = false;
        for (int i{0}; i < 26; i++)
        {
            // 빠른 알파벳 부터 탐색을 해준다.
            // 맞춰야할 짝이 있는지 여부부터 파악
            if (alpha[i].empty())
                continue;
            if (checkroute(i))
            {
                // 가능한 경로라면 두 타일을 '.'으로 바꾸어주기
                check[alpha[i][0].y][alpha[i][0].x] = '.';
                check[alpha[i][1].y][alpha[i][1].x] = '.';
                // 알파벳 좌표도 초기화해서 맞춘 알파벳 짝을 제외
                alpha[i].clear();
                answer += i + 'A';
                // 짝을 맞췄으면 다시 A부터 탐색해주기
                possible = true;
                break;
            }
        }
    }
    // 남은 칸을 모두 탐색해서 알파벳 타일이 남았는지를 체크
    // 남았다면 IMPOSSIBLE
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (check[i][j] != '.' && check[i][j] != '*')
                answer = "IMPOSSIBLE";
        }
    }
    return answer;
}
