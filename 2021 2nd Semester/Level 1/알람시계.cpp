#include <iostream>
using namespace std;

int main() {
	int H, M;
	cin >> H >> M;

	if (M >= 45 && M <= 59) {
		M = M - 45;
	}
	else if (M < 45 && M >= 0) {
		M = M - 45 + 60;
		if (H >= 1 && H <= 23) {
			H = H - 1;
		}
		else if (H == 0){
			H = H - 1 + 24;
		}
	}

	cout << H << " " << M << endl;
}