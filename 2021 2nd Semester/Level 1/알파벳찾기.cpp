#include <iostream>
#include <string>
using namespace std;
int main() {
    string str; // �Է¹��� ���ڿ�
    string alpha = "abcdefghijklmnopqrstuvwxyz"; // ���ĺ� ��ü�� ���� ���ڿ�
    int loc[26] = { 0 };    // ���ĺ� ���� ���ڿ��� �� ��°���� ù ��°�� �����ϴ����� ���
    cin >> str;
    for (int i = 0; i < 26; i++) {  // -1�� �ʱ�ȭ
        loc[i] = -1;
    }
    for (int i = 0; i < 26; i++) {  // a���� z������ �������� ���ڿ� ���� ���ĺ��� ���� Ž��
        for (int j = 0; j < str.length(); j++) {
            if (alpha[i] == str[j]) {   // ���� ���, a�� �������� ���� �� ���ڿ� ������ a�� ó������ �����ٸ�,
                loc[i] = j; // �� ���ڿ� ���� a�� ��ġ(j��°)�� loc �迭 ���� ���ĺ� ������ ���� a�� ��ġ(0��°)�� ����
                break;
            }
        }
    }
    for (int i : loc) { // loc �迭 ���� ��� ���Ҹ� ���
        cout << i << " ";
    }
    return 0;
}