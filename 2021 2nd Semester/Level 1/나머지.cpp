#include <iostream>
#include <set>
using namespace std;

int main() {
	int N; //입력 받을 수
	set<int> S; //key라고 불리는 원소들의 집합, 기본적으로 자동 오름차순 정렬, 중복을 허용하지 않음

	for (int i = 0; i < 10; i++) {
		cin >> N;
		S.insert(N % 42); //입력 받은 수를 42로 나눈 나머지를 삽입
	}

	cout << S.size() << endl; //set이 중복을 허용하지 않으므로 서로 다른 나머지값들만 저장, 그 크기만을 출력
	
	return 0;
}