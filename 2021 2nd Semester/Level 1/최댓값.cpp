#include <iostream>
using namespace std;

int main() {
	int max = 0;	//�ִ�
	int idx = 0;	//�Է°��� ����� �迭 ���� �ִ��� �ε���	
	int arr[9]{ 0 };	// �Է°��� ���� �迭

	for (int i = 0; i < 9; i++) { // ���� �ٸ� 9���� �ڿ��� �Է�
		cin >> arr[i];
	}

	for (int i = 0; i < 9; i++) { // �ִ� �� �ִ��� ��ġ Ž��
		if (i == 0) { max = arr[i]; }
		else {
			if (arr[i] > max) { 
				max = arr[i];
				idx = i;
			}
		}
	}

	cout << max << endl; // �ִ� ���
	cout << idx + 1 << endl; // �迭�� �ε��� + 1 = �ִ��� ��ġ

	return 0;
}