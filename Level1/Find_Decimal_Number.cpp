#include <iostream>

using namespace std;

int main() {

    int N, n, num = 0;
    int arr[1001] = { 1,1 };

    for (int i = 2; (i * i) < 1001; i++) {
        if (arr[i] == 0) {
            for (int j = i * i; j < 1001; j += i)
                arr[j] = 1;
        }
    }

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> n;
        if (arr[n] == 0)
            num++;
    }
    cout << num;
    return 0;
}

