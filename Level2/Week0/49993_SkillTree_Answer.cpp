#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();
    for(int i{0}; i < skill_trees.size(); i++) {
        // 첫 선행 스킬은 skill의 첫 스킬과 같은 스킬인지 판단하면 된다.
        int min_precede_skill = 0;
        for(int j{0}; j < skill_trees[i].length(); j++) {
            // 해당 스킬이 skill에 속해 있지 않으면 넘긴다.
            if(skill.find(skill_trees[i][j]) == string::npos) {
                continue;
            }
            // 해당 스킬이 이번에 검사해야할 선행 스킬이 맞는지를 판단한다. 
            if(min_precede_skill == skill.find(skill_trees[i][j])) {
                min_precede_skill++;
            } else{
                answer--;
                break;
            }
        }
    }
    return answer;
}

int main() {
    string skill = "CBD";
    vector<string>skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};
    cout << solution(skill,skill_trees) << "\n";
}
