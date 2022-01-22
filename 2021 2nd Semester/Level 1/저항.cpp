#include <iostream>
#include <map>
#include <cmath>
#include <string>
using namespace std;

int main() {
    map<string, int>v={{"black", 0},{"brown", 1},{"red", 2},{"orange", 3},{"yellow", 4},
                       {"green", 5},{"blue", 6},{"violet", 7},{"grey", 8},{"white", 9}};
    map<string, int>x={{"black", 1},{"brown", 10},{"red", 100},{"orange", 1000},{"yellow", 10000},
                       {"green", 100000},{"blue", 1000000},{"violet", 10000000},{"grey", 100000000},{"white", 1000000000}};

    string key;
    long long a = 0;
    for (int i = 1; i >= 0; i--) {
        cin >> key;
        a += v.find(key)->second * pow(10, i);
    }
    cin >> key;
    a *= x.find(key)->second;
    cout << a;
}
