#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int solution(string s)
{
    int answer=0;
    int sl = s.length();
    // 길이가 1인 문자열이면 무조건 1
    if(sl == 1) return 1;
    for(int i{0}; i < sl - 1; i++) {
        // 부분문자열이 홀수인 경우부터 체크
        int res = 1;
        int left = i-1, right = i+1;
        // 중심점으로부터 팰린드롬의 길이를 늘려서 가장 긴 길이를 찾기
        while(left >= 0 && right < sl) {
            if(s[left] == s[right]) res += 2;
            else break;
            left--; right++;
        }
        answer = max(answer, res);
        // 부분문자열이 짝수인 경우 체크
        res = 0;
        left = i, right = i+1;
        // 중심점으로부터 팰린드롬의 길이를 늘려서 가장 긴 길이를 찾기
        while(left >= 0 && right < sl) {
            if(s[left] == s[right]) res += 2;
            else break;
            left--; right++;
        }
        answer = max(answer, res);
    }

    return answer;
}
