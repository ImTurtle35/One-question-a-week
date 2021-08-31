#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int one = 0;
    int two = 1;
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    for (int i = 1; i < n; i++) {
        answer = (one + two)%1234567;
        one = two%1234567;
        two = answer%1234567;
    }

    return answer;
}
