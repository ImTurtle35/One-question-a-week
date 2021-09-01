#include <vector>
 
using namespace std;
 
vector<int> solution(int brown, int red) {
    vector<int> answer;
    int sum = brown + red;
    for (int height = 3; ; height++) {
        if (!(sum % height)) {
            int weight = sum / height;
            if (((height - 2) * (weight - 2)) == red) {
                answer.push_back(weight);
                answer.push_back(height);
                break;
            }
        }
    }
    return answer;
}
