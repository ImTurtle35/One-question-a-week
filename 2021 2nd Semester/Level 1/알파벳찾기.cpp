#include <iostream>
#include <string>
using namespace std;
int main() {
    string str; // 입력받을 문자열
    string alpha = "abcdefghijklmnopqrstuvwxyz"; // 알파벳 전체를 담은 문자열
    int loc[26] = { 0 };    // 알파벳 별로 문자열의 몇 번째에서 첫 번째로 등장하는지를 기록
    cin >> str;
    for (int i = 0; i < 26; i++) {  // -1로 초기화
        loc[i] = -1;
    }
    for (int i = 0; i < 26; i++) {  // a부터 z까지를 기준으로 문자열 내의 알파벳을 전부 탐색
        for (int j = 0; j < str.length(); j++) {
            if (alpha[i] == str[j]) {   // 예를 들어, a를 기준으로 했을 때 문자열 내에서 a를 처음으로 만난다면,
                loc[i] = j; // 그 문자열 내의 a의 위치(j번째)를 loc 배열 내의 알파벳 순서에 따른 a의 위치(0번째)에 저장
                break;
            }
        }
    }
    for (int i : loc) { // loc 배열 내의 모든 원소를 출력
        cout << i << " ";
    }
    return 0;
}