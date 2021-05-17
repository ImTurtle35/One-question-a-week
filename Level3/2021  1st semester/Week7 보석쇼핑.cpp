#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string,int>mp;
    for(auto i:gems) {
        mp[i] = 0;
    }
    int cnt = 0;
    int start = 0, end = 0;
    int start_res = 0,end_res = gems.size();
    while(true) {
        if(cnt < mp.size()) {
            if(end == gems.size()) break;
            if(!mp[gems[end]])cnt++;
            mp[gems[end]]++;
            end++;
        }
        else {
            if(end - start < end_res - start_res) {
                start_res = start;
                end_res = end;
            }
            if(mp[gems[start]] == 1) {
                cnt--;
            }
            mp[gems[start]]--;
            start++;
        }
    }
    answer.push_back(start_res+1);
    answer.push_back(end_res);
    return answer;
}
