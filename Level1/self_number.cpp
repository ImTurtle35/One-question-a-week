#include <iostream>
using namespace std;
// �� �ڸ��� ���ڸ� ���� ���� ������ ���� ���� �ѹ�, �����ڰ� ���� ����
int d(int num) {
	int sum = 0;
	sum += num; // �ڱ� �ڽ� ���ϱ�

	while (1) {
		if (num == 0) break; // ���̻� ���� �ڸ����� ���� ���, ����
		else {
			sum += num % 10; // �� �ڸ��� ���� ���ϱ�
			num = num / 10; // ������ �ڸ��� ���ڸ� ����
		}
	}

	return sum;
}

int main() {
	bool arr[10001]; // 1 ~ 10000������ ���� �߿��� ���� �ѹ��� ã�� ���� �迭
					// ���� �ѹ����� �ƴ����� true�� false�� �з�
	int idx = 0;

	for (int i = 1; i <= 10000; i++) {
		arr[i] = true; // ��ü �迭 ���� true�� �ʱ�ȭ
	}

	for (int i = 1; i <= 10000; i++) {
		idx = d(i); // �����ڰ� �ִ� ���� ����
		if (idx <= 10000) { // �� �־��ָ� �ε��� ���� �߻�
			// �����ڰ� �ִ� ���� (= ���� �ѹ��� �ƴ� ��)�� false�� ����
			arr[idx] = false; 
		}
	}

	for (int i = 1; i <= 10000; i++) {
		if (arr[i]) { // ���� �ѹ� �Ǻ� �迭(true or false)�� ���� ��� ����
			cout << i << endl; // �ε����� ���� �����ϰ� ���
		} 
	}
	return 0;
}

