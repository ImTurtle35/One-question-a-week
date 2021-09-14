#include <iostream>
#include <string>
using namespace std;

// �ùٸ� ��ȣ ���ڿ����� Ȯ��
bool isCheck(string s) {
	int cnt = 0;
	
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];

		if (c == '(') cnt++;
		else if (c == ')') cnt--;

		// �ùٸ��� ���� ���ڿ��� ���, 
		// ������ �Ǵ� ������ �߻�
		if (cnt < 0) { return false; }
	}

	return cnt == 0;
}

string solution(string p) {
	// 1. �Է��� �� ���ڿ��� ���, �� ���ڿ��� ��ȯ
	if (p == "") return p;

	// 2. ���ڿ� p(= w)�� �������� ��ȣ ���ڿ� u, v�� �и� 
	int cnt = 0;
	string u, v;
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '(') cnt++;
		else if (p[i] == ')') cnt--;
		// '('�� ')'�� ������ ���ٸ�, �������� ��ȣ ���ڿ�
		if (cnt == 0) {
			u = p.substr(0, i + 1);
			v = p.substr(i + 1);
			break;
		}
	}
	// 3. ���ڿ� u�� �ùٸ� ��ȣ ���ڿ��� ���
	// 3-1.���ڿ� v�� ���� 1�ܰ���� �ٽ� ����
	if (isCheck(u)) { return u + solution(v); }

	// 4. ���ڿ� u�� �ùٸ� ��ȣ ���ڿ��� �ƴ� ���
	// 4-1. �� ���ڿ��� ù ��° ���ڷ� '('�� ����
	string ret = "(";

	// 4-2. ���ڿ� v�� ���� 1�ܰ���� ��������� ������ ����� �̾� ����
	ret += solution(v);

	// 4-3. ')'�� �ٽ� ����
	ret += ")";

	// 4-4. u�� ù ��°�� ������ ���ڸ� �����ϰ�,
	u = u.substr(1, u.size() - 2);

	// ������ ���ڿ��� ��ȣ ������ ����� �ڿ� ����
	for (int i = 0; i < u.size(); i++) {
		if (u[i] == '(') { ret += ")"; }
		else if (u[i] == ')') { ret += "("; }
	}

	// 4-5. ������ ���ڿ��� ��ȯ
	return ret;
}

int main() {
	string w = "(()())()";
	cout << solution(w) << endl;
}