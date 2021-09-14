#include <iostream>
#include <string>
using namespace std;

// 올바른 괄호 문자열인지 확인
bool isCheck(string s) {
	int cnt = 0;
	
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];

		if (c == '(') cnt++;
		else if (c == ')') cnt--;

		// 올바르지 않은 문자열일 경우, 
		// 음수가 되는 지점이 발생
		if (cnt < 0) { return false; }
	}

	return cnt == 0;
}

string solution(string p) {
	// 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환
	if (p == "") return p;

	// 2. 문자열 p(= w)를 균형잡힌 괄호 문자열 u, v로 분리 
	int cnt = 0;
	string u, v;
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '(') cnt++;
		else if (p[i] == ')') cnt--;
		// '('와 ')'의 개수가 같다면, 균형잡힌 괄호 문자열
		if (cnt == 0) {
			u = p.substr(0, i + 1);
			v = p.substr(i + 1);
			break;
		}
	}
	// 3. 문자열 u가 올바른 괄호 문자열인 경우
	// 3-1.문자열 v에 대해 1단계부터 다시 수행
	if (isCheck(u)) { return u + solution(v); }

	// 4. 문자열 u가 올바른 괄호 문자열이 아닌 경우
	// 4-1. 빈 문자열에 첫 번째 문자로 '('를 붙임
	string ret = "(";

	// 4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과를 이어 붙임
	ret += solution(v);

	// 4-3. ')'를 다시 붙임
	ret += ")";

	// 4-4. u의 첫 번째와 마지막 문자를 제거하고,
	u = u.substr(1, u.size() - 2);

	// 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙임
	for (int i = 0; i < u.size(); i++) {
		if (u[i] == '(') { ret += ")"; }
		else if (u[i] == ')') { ret += "("; }
	}

	// 4-5. 생성된 문자열을 반환
	return ret;
}

int main() {
	string w = "(()())()";
	cout << solution(w) << endl;
}