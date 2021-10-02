#include <iostream>
using namespace std;

int main() {
	int max = 0;	//최댓값
	int idx = 0;	//입력값이 저장된 배열 내의 최댓값의 인덱스	
	int arr[9]{ 0 };	// 입력값을 받을 배열

	for (int i = 0; i < 9; i++) { // 서로 다른 9개의 자연수 입력
		cin >> arr[i];
	}

	for (int i = 0; i < 9; i++) { // 최댓값 및 최댓값의 위치 탐색
		if (i == 0) { max = arr[i]; }
		else {
			if (arr[i] > max) { 
				max = arr[i];
				idx = i;
			}
		}
	}

	cout << max << endl; // 최댓값 출력
	cout << idx + 1 << endl; // 배열의 인덱스 + 1 = 최댓값의 위치

	return 0;
}