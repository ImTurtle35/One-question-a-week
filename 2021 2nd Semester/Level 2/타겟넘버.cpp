#include <iostream>
#include <vector>
using namespace std;
int answer = 0;

void dfs(vector<int> numbers, int target, int total, int index) {
    if (index == numbers.size()) {
        if (total == target) answer++;
        return;
    }
    dfs(numbers, target, total + numbers[index], index + 1);
    dfs(numbers, target, total - numbers[index], index + 1);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return answer;
}

int main() {
    vector<int> numbers = { 1, 2, 3 };
    int target = 0;

    cout << solution(numbers, target) << endl;
}