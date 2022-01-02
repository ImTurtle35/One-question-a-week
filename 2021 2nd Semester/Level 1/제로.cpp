#include <iostream>
#include <vector>
using namespace std;
int main() {
	int K, Num, Sum = 0; // K는 정수를 입력받을 횟수, Num은 입력받을 정수, Sum은 입력받을 정수의 합계
	vector<int> Arr; // 입력받은 정수를 저장할 배열을 선언

	cin >> K;
	for (int i = 0; i < K; i++) {	// 정수를 입력받는 과정을 K번 반복
		cin >> Num;
		if (Num == 0) {			// 0을 입력받으면, 
			Arr.pop_back();		// 가장 최근에 쓴 수는 마지막으로 배열에 삽입된 수를 의미하므로 배열에 삽입된 마지막 원소를 제거 
		}
		else {
			Arr.push_back(Num);	// 0이 아니면, 배열에 삽입
		}
	}

	for (int i = 0; i < Arr.size(); i++) {	// 배열 내의 모든 원소들의 합을 계산
		Sum += Arr[i];
	}

	cout << Sum << endl;	// 최종적으로 적어낸 수의 합계를 출력
		
	return 0;
}