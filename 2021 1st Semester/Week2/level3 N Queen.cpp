#include <string>
#include <vector>

using namespace std;

bool checkQueen(vector<int>queen, int idx){
    for(int i=0;i<idx;i++){
        if(queen[i]==queen[idx]) return false;
        if(abs(queen[i]-queen[idx]) == abs(i-idx)) return false;
    }
    return true;
}

void backtrack(vector<int>&queen, int cnt, int& answer, int N){
    if(cnt == N){
        answer++;
        return;
    }
    for(int i = 0; i < N; i++){
        queen.push_back((i));
        if(checkQueen(queen,cnt))
            backtrack(queen, cnt+1, answer, N);
		queen.pop_back();
    }
}

int solution(int n) {
    int answer = 0;
    vector<int>queen;
    backtrack(queen, 0, answer, n);
    return answer;
}
