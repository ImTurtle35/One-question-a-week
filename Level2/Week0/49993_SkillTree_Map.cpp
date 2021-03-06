#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();
    // 선행스킬을 key로, 선행스킬의 순서를 value로 사용하는 map을 생성  
    map<char,int>skill_map;
    for(int i{0}; i < skill.length(); i++) {
        skill_map.insert({skill[i],i});
    }
    for(int i{0}; i < skill_trees.size(); i++) {
        // 첫 선행 스킬은 skill의 첫 스킬과 같은 스킬인지 판단하면 된다.
        int min_precede_skill = 0;
        for(int j{0}; j < skill_trees[i].length(); j++) {
            // 해당 스킬이 skill에 속해 있지 않으면 넘긴다.(map에 해당 key가 없으면 find()는 map.end()값을 반환한다.)
            if(skill_map.find(skill_trees[i][j]) == skill_map.end()) continue;
            // 해당 스킬이 이번에 검사해야할 선행 스킬이 맞는지를 판단한다.
            if(skill_map[skill_trees[i][j]] == min_precede_skill) {
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
