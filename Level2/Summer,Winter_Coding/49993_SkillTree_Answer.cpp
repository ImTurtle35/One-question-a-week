#include <string>
#include <vector>

using namespace std;

/*
1. 선행 스킬이 존재하는 스킬은 반드시 선행하는 모든 스킬을 찍어야 찍을 수 있다.
2. 즉, 선행 스킬에 영향을 받는 스킬인가?
3. 영향을 받는 스킬이면 앞의 선행 스킬을 찍었는가? 여부를 파악해야 한다.
*/

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();
    // 알파벳은 모두 26글자인것을 이용해 선행 스킬의 순서를 저장하는 배열을 구성 (선행 스킬에 포함되지 않는 스킬들에는 -1을 부여)
    int skill_order[26];
    for(int i{0};i < 26; i++) {
        skill_order[i] = -1;
    }
    for(int i{0}; i < skill.length(); i++) {
        // 문자열은 char로 이루어진 배열! 첫 글자는 배열의 0번째 칸에 해당하므로 마지막 글자는 '문자열의 길이 - 1'번째 칸에 위치한다.
        // char형으로 만든 문자는 'ASCII' 코드에 따라 정수의 형태로 전환이 가능하다. (표를 참조)
        // 이를 이용해 알파벳과 몇 번째 선행 스킬인지를 대응시켜 배열에 저장한다.
        skill_order[skill[i] - 'A'] = i;
    }
    
    for(int i{0}; i < skill_trees.size(); i++) {
        // 가장 선행되는 스킬부터 확인되어야 한다.
        int min_skill = 0;
        for(int j{0}; j < skill_trees[i].length(); j++) {
            int cn = skill_trees[i][j] - 'A';
            // -1인 경우는 선행 스킬의 영향을 받지 않는 스킬이다.
            if(skill_order[cn] == -1) continue;
            // 선행 스킬의 영향을 받는 스킬이므로 선행 스킬이 찍혀있는지를 확인한다.
            if(min_skill == key[cn]) {
                min_skill++;
            }
            // 해당하지 않으면 불가능한 스킬트리이므로 더 이상 비교할 이유가 없다.
            else{
                answer--;
                break;
            }
        }
    }
    return answer;
}
