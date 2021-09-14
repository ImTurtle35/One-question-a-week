#include <iostream>
#include <stack>
using namespace std;

int solution(string s) {
	stack<char> stk;
	for (int i = 0; i < s.length(); i++) {
		if (stk.empty() || s[i] != stk.top()) { stk.push(s[i]); }
		else if (s[i] == stk.top()) { stk.pop(); }
	}

	if (stk.empty()) { return 1; }
	else { return 0; }
}

int main() {
	string str;
	cin >> str;
	
	cout << solution(str) << endl;
}
