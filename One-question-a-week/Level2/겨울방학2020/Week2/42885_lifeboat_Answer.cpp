#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    // 가장 무거운 사람, 가장 가벼운 사람을 쉽게 파악하기 위해 오름차순으로 정렬해준다.
    sort(people.begin(), people.end());
    int heavy = people.size() - 1, light = 0;
    while(heavy >= light) {
        /* 1. 가장 무거운 인원의 무게 + 가장 가벼운 인원의 무게 > limit

           = 함께 구명보트에 오를 수 없으므로 가장 무거운 인원만 태워야 한다.
    
           2. 가장 무거운 인원의 무게 + 가장 가벼운 인원의 무게 <= limit

           = 함께 태워도 되므로 두 명을 같이 태울 수 있다. */
        if(people[heavy] + people[light] <= limit) {
            light++;
        }
        heavy--;
        answer++;
    }
    return answer;
}
