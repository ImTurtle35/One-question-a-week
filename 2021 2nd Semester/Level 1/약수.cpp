#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<long long> a;
    int n;
    long long num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        a.push_back(num);
    }
    sort(a.begin(), a.end(), greater<long long>());
    long long num1 = a.front() * a.back();
    cout << num1 << endl;
}
