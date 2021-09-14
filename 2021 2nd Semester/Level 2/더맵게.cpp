#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < scoville.size(); i++) {
		pq.push(scoville[i]);
	}

	while (pq.top() < K) {
		if (pq.size() == 1) { break;}

		int min1 = pq.top(); 
		pq.pop();
		int min2 = pq.top() * 2;
		pq.pop();

		pq.push(min1 + min2);
		answer++;
	}

	if (pq.top() < K) { return -1; }

	return answer;
}

int main() {
	vector<int> sco = { 1,2,3,9,10,12 };
	int k = 7;
	cout << solution(sco, k) << endl;
}
