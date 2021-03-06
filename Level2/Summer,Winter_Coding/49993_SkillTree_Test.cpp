#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();
    // 알파벳은 모두 26글자! 
    int key[26];
    for(int i{0};i < 26; i++) {
        key[i] = -1;
    }
    for(int i{0}; i < skill.length(); i++) {
        key[skill[i] - 'A'] = i;
    }
    for(int i{0}; i < skill_trees.size(); i++) {
        int min_skill = 0;
        for(int j{0}; j < skill_trees[i].length(); j++) {
            int cn = skill_trees[i][j] - 'A';
            if(key[cn] == -1) continue;
            if(min_skill == key[cn]) {
                min_skill++;
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