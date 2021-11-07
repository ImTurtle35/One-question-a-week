#include <iostream>
#include <iomanip>  //iomanip�� setprecision()�� ����
using namespace std;
int main() {
    int C = 0, N = 0;   // �׽�Ʈ ���̽��� ���� �л��� ��
    cin >> C;
    for (int i = 0; i < C; i++) {   // �׽�Ʈ ���̽� ����ŭ �ݺ�
        cin >> N;
        int score[1000] = { 0 }, sum = 0;   // N���� ������ ���� �迭�� ������ �հ�
        double avg = 0.00;      // ���
        for (int j = 0; j < N; j++) {
            cin >> score[j];
            sum += score[j];    // ������ ������ ���ϰ�,
        }
        avg = (double)sum / N;  // ����� ����
        int count = 0;  // ����� �Ѵ� �л��� �� ����
        for (int j = 0; j < N; j++) {
            if (avg < score[j]) {
                count++;    // ����� �Ѵ� �л��� ��Ÿ�� ������ 1�� ����
            }
        }
        // (����� �Ѵ� �л� �� / ��ü �л� ��) * 100
        cout << fixed << setprecision(3) << (double)count * 100 / N << "%" << endl;
        // fixed : �Ҽ����� �����ؼ� ǥ��, �Ҽ��� �Ʒ����� ����� ����
        // setprecision(n) : ���� ū �ڸ������� n�ڸ��� ���, fixed�� ���� �ÿ� �Ҽ��� �Ʒ� n�ڸ� ���
        // (�ڷ���)���� : �� ��ȯ ex) (double)count = int�� ������ count�� double������ ��ȯ
    }
    return 0;
}