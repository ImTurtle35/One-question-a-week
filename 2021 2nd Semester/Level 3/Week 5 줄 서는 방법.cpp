#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> num;
    long long fac = 1;
    long long num_of_num;
    long long index;
    for(int i{1}; i <= n; i++) {
        fac *= i;
        num.push_back(i);
    }
    for(int i{n}; i > 0; i--) {
        num_of_num = fac/i;
        index = (k-1)/num_of_num;
        answer.push_back(num[index]);
        num.erase(num.begin() + index);
        n--;
        k %= num_of_num;
        if( k == 0) k = num_of_num;
    }
    
    return answer;
}
