#include <iostream>
using namespace std;
// 각 자리의 숫자를 더한 수를 제외한 것이 셀프 넘버, 생성자가 없는 숫자
int d(int num) {
	int sum = 0;
	sum += num; // 자기 자신 더하기

	while (1) {
		if (num == 0) break; // 더이상 더할 자릿수가 없는 경우, 종료
		else {
			sum += num % 10; // 각 자리의 숫자 더하기
			num = num / 10; // 더해준 자리의 숫자를 제외
		}
	}

	return sum;
}

int main() {
	bool arr[10001]; // 1 ~ 10000까지의 숫자 중에서 셀프 넘버를 찾기 위한 배열
					// 셀프 넘버인지 아닌지를 true와 false로 분류
	int idx = 0;

	for (int i = 1; i <= 10000; i++) {
		arr[i] = true; // 전체 배열 내를 true로 초기화
	}

	for (int i = 1; i <= 10000; i++) {
		idx = d(i); // 생성자가 있는 숫자 도출
		if (idx <= 10000) { // 안 넣어주면 인덱스 오류 발생
			// 생성자가 있는 숫자 (= 셀프 넘버가 아닌 수)를 false로 지정
			arr[idx] = false; 
		}
	}

	for (int i = 1; i <= 10000; i++) {
		if (arr[i]) { // 셀프 넘버 판별 배열(true or false)에 따라 출력 결정
			cout << i << endl; // 인덱스를 수로 생각하고 출력
		} 
	}
	return 0;
}

