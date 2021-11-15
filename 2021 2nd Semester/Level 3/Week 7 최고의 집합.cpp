#include <string>
#include <vector>

using namespace std;

int res;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int a = s/n;
    int b = s%n;
    if(a == 0) {
        answer.push_back(-1);
    }
    else {
        for(int i{0}; i < n-b; i++) {
            answer.push_back(a);
        }
        for(int i{n-b}; i < n; i++) {
            answer.push_back(a+1);
        }
    }
    return answer;
}
