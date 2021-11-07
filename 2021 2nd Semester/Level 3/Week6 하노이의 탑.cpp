#include <string>
#include <vector>
#include <iostream>

using namespace std;

void hanoi(vector<vector<int>>& answer, int n, int start, int dest) {
    if(n == 1) {
        answer.push_back({start,dest});
    }
    else {
        hanoi(answer,n-1,start,6-start-dest);
        answer.push_back({start,dest});
        hanoi(answer,n-1,6-start-dest,dest);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(answer,n,1,3);
    return answer;
}
