#include <iostream>
#include <vector>
using namespace std;
int main() {
	int K, Num, Sum = 0; // K�� ������ �Է¹��� Ƚ��, Num�� �Է¹��� ����, Sum�� �Է¹��� ������ �հ�
	vector<int> Arr; // �Է¹��� ������ ������ �迭�� ����

	cin >> K;
	for (int i = 0; i < K; i++) {	// ������ �Է¹޴� ������ K�� �ݺ�
		cin >> Num;
		if (Num == 0) {			// 0�� �Է¹�����, 
			Arr.pop_back();		// ���� �ֱٿ� �� ���� ���������� �迭�� ���Ե� ���� �ǹ��ϹǷ� �迭�� ���Ե� ������ ���Ҹ� ���� 
		}
		else {
			Arr.push_back(Num);	// 0�� �ƴϸ�, �迭�� ����
		}
	}

	for (int i = 0; i < Arr.size(); i++) {	// �迭 ���� ��� ���ҵ��� ���� ���
		Sum += Arr[i];
	}

	cout << Sum << endl;	// ���������� ��� ���� �հ踦 ���
		
	return 0;
}