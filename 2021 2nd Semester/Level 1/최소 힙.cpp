#include <iostream>
#include <vector>	//priority queue를 사용하기 위해 vector, queue 라이브러리 추가가 필요
#include <queue>
#include <functional>	//greater, 오름차순이라는 조건을 활용하기 위해서 functional 라이브러리 추가가 필요
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	//시간초과 문제를 해결하도록 하는 부분, endl 대신에 '\n'로 대신 활용하는 부분도 필요
	cin.tie(NULL);
	cout.tie(NULL);

	int N, x; //N은 연산의 개수, x는 연산에 대한 정보
	cin >> N;	//연산의 개수를 입력 
	priority_queue<int, vector<int>, greater<int>> pq;	//최소 힙을 구현, 최소 힙은 숫자가 작을 수록 우선순위가 높음

	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == 0) { //x에 0이 입력된 경우
			if (pq.empty()) { //배열이 비어있는 경우인데, 가장 작은 값을 출력하라고 한 경우
				cout << 0 << '\n'; //0을 출력
			} 
			else {	//배열이 비어있지 않은 경우
				cout << pq.top() << '\n'; //오름차순으로 정렬된 우선순위 큐에 의해 가장 작은 수를 출력
				pq.pop(); //큐 내에서 제거
			}
		}
		else {	//x가 자연수인 경우
			pq.push(x); 
		}
	}

	return 0;
}