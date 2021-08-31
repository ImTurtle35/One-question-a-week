#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;
    string str="";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            v.push_back(atoi(str.c_str()));
            str = "";
        }
        else {
            str += s[i];
        }
    }
    v.push_back(atoi(str.c_str()));
    sort(v.begin(), v.end());
    
    answer = to_string(v[0]) + ' ' + to_string(v.back());
    return answer;
}
