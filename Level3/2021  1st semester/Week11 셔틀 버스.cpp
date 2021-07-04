#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int stringtoint(string stringtime) {
    int inttime = (stringtime[0] - '0') * 600;
    inttime += (stringtime[1] - '0') * 60;
    inttime += (stringtime[3] - '0') * 10;
    inttime += (stringtime[4] - '0');
    return inttime;
}

string inttostring(int inttime) {
    string stringtime = "";
    stringtime += (inttime / 600) + '0';
    inttime %= 600;
    stringtime += (inttime / 60) + '0';
    inttime %= 60;
    stringtime += ':';
    stringtime += (inttime / 10) + '0';
    inttime %= 10;
    stringtime += (inttime) + '0';
    return stringtime;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int>crew;
    for(int i{0}; i < timetable.size(); i++) {
        crew.push_back(stringtoint(timetable[i]));
    }
    sort(crew.begin(),crew.end());
    int curtime = 540, youarrive = 539, crew_idx = 0;
    for(int i{0}; i < n; i++) {
        int shuttlein = 0;
        for (int j{crew_idx}; j < crew.size(); j++) {
            if (crew[j] > curtime) break;
            crew_idx++;
            shuttlein++;
            if (shuttlein == m) break;
        }
        if (i == n-1) {
            if (shuttlein == m) youarrive = crew[crew_idx - 1] - 1;
            else youarrive = curtime;
        }
        curtime += t;
    }
    answer = inttostring(youarrive);
    
    return answer;
}
