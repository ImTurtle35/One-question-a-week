#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int cur = 1;
    int index = 0;
    while(cur <= n) {
        if(cur >= stations[index] - w && cur <= stations[index] + w) {
            cur = stations[index] + w + 1;
            index++;
        }
        else {
            answer++;
            cur += w * 2 + 1;
        }
    }
    return answer;
}
