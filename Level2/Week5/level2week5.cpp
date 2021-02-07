#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int arr[1001][1001];
    int x = 1, y = 1, count = 1, limit = n, num = (n*(n+1))/2;
    int direction = 0; // 0 = 아래방향, 1 = 우측방향, 2 = 좌상 방향
    for(int i{1}; i <= num ; i++, count++) {
        arr[y][x] = i;
        if(direction == 0 && count == limit){
            direction = 1; count = 0; limit--;
        }
        else if (direction== 1 && count == limit){
            direction = 2; count = 0; limit--;
        }
        else if (direction == 2 && count == limit) {
            direction = 0; count = 0; limit--;
        }
        if(direction == 0)
            y++;
        else if (direction == 1)
            x++;
        else if (direction == 2) {
            y--; x--;
        }
    }
    for(int i{1}; i <= n; i++) {
        for(int j{1}; j <= i; j++) {
            answer.push_back(arr[i][j]);
        }
    }
    return answer;
}
