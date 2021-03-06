#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow; // sum = height * side;
    int height = 3;
    int side = sum/height;
    // 제한사항에 따라 카펫의 가로가 세로 이하 일때 까지만 탐색해주면
    // 반드시 해답이 나온다!
    while(!(side < height)){
        // height와 side로 yellow를 구해 비교한다.
        if (((height - 2) * (side - 2)) == yellow) {
            answer.push_back(side);
            answer.push_back(height);
            break;
        }
        height++;
        side = sum/height;
    }
    return answer;
}
