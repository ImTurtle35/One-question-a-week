#include <iostream>
#include <set>
using namespace std;

int main() {
	int N; //�Է� ���� ��
	set<int> S; //key��� �Ҹ��� ���ҵ��� ����, �⺻������ �ڵ� �������� ����, �ߺ��� ������� ����

	for (int i = 0; i < 10; i++) {
		cin >> N;
		S.insert(N % 42); //�Է� ���� ���� 42�� ���� �������� ����
	}

	cout << S.size() << endl; //set�� �ߺ��� ������� �����Ƿ� ���� �ٸ� ���������鸸 ����, �� ũ�⸸�� ���
	
	return 0;
}