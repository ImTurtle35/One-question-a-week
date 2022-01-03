#include <string>
#include <vector>

using namespace std;

int video[3600001];

int strtoint(string strtime) {
    int inttime = 0;
    inttime += stoi(strtime.substr(0,2)) * 3600;
    inttime += stoi(strtime.substr(3,2)) * 60;
    inttime += stoi(strtime.substr(6,2));
    return inttime;
}

string inttostr(int inttime) {
    string strtime = "";
    int hour = inttime / 3600;
    if(hour < 10) strtime += "0";
    strtime += to_string(hour);
    strtime += ":";
    int minit = (inttime % 3600) / 60;
    if(minit < 10) strtime += "0";
    strtime += to_string(minit);
    strtime += ":";
    int sec = inttime % 60;
    if(sec < 10) strtime += "0";
    strtime += to_string(sec);
    return strtime;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int pt = strtoint(play_time);
    int at = strtoint(adv_time);
    for(int i{0}; i < logs.size(); i++) {
        int start = strtoint(logs[i].substr(0,8));
        int end = strtoint(logs[i].substr(9,8));
        for(int j{start}; j < end; j++) {
            video[j]++;
        }
    }
    long long int sum = 0;
    for(int i{0}; i < at; i++) {
        sum += video[i];
    }
    long long int maxsum = sum;
    long long int ans = 0;
    for(int i{at}; i < pt; i++) {
        sum += video[i];
        sum -= video[i - at];
        if(sum > maxsum) {
            maxsum = sum;
            ans = i - at + 1;
        }
    }
    return answer = inttostr(ans);
}
