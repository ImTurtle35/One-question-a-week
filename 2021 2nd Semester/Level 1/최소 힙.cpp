#include <iostream>
#include <vector>	//priority queue�� ����ϱ� ���� vector, queue ���̺귯�� �߰��� �ʿ�
#include <queue>
#include <functional>	//greater, ���������̶�� ������ Ȱ���ϱ� ���ؼ� functional ���̺귯�� �߰��� �ʿ�
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	//�ð��ʰ� ������ �ذ��ϵ��� �ϴ� �κ�, endl ��ſ� '\n'�� ��� Ȱ���ϴ� �κе� �ʿ�
	cin.tie(NULL);
	cout.tie(NULL);

	int N, x; //N�� ������ ����, x�� ���꿡 ���� ����
	cin >> N;	//������ ������ �Է� 
	priority_queue<int, vector<int>, greater<int>> pq;	//�ּ� ���� ����, �ּ� ���� ���ڰ� ���� ���� �켱������ ����

	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == 0) { //x�� 0�� �Էµ� ���
			if (pq.empty()) { //�迭�� ����ִ� ����ε�, ���� ���� ���� ����϶�� �� ���
				cout << 0 << '\n'; //0�� ���
			} 
			else {	//�迭�� ������� ���� ���
				cout << pq.top() << '\n'; //������������ ���ĵ� �켱���� ť�� ���� ���� ���� ���� ���
				pq.pop(); //ť ������ ����
			}
		}
		else {	//x�� �ڿ����� ���
			pq.push(x); 
		}
	}

	return 0;
}