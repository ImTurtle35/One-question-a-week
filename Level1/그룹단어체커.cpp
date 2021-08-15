#include <iostream>
using namespace std;

int main() {
    int n, num = 0;
    char prev;
    string s;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        bool arr[27] = { 0, };
        for (int j = 0; j < s.length(); j++) {
            int idx = s[j] - 97;
            if (arr[idx] == 0) {
                arr[idx] = 1;
                prev = s[j];
            }
            else if (arr[idx] == 1 && prev != s[j]) {
                num--;
                break;
            }
        }
        num++;
    }
    cout << num << endl;
}
