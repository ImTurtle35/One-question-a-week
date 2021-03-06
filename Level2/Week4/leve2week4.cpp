#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int>answer;
    queue<int>save;
    for(int i{0}; i < progresses.size(); i++) {
        int left_progress = 100 - progresses[i];
        if(left_progress%speeds[i] == 0) {
            save.push(left_progress/speeds[i]);
        } else {
            save.push(left_progress/speeds[i] + 1);
        }
    }
    int priority_util = save.front();
    save.pop();
    int count = 1;
    while(!save.empty()) {
        int cur = save.front();
        save.pop();
        if(cur > priority_util)  {
            priority_util = cur;
            answer.push_back(count);
            count = 0;
        }
        count++;
     }
    answer.push_back(count);
    return answer;
}
