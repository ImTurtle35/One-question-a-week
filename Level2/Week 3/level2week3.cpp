#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string s1, string s2) {
    //ex:) s1 = 10, s2 = 9이면 s1+s2 = 109, s2+s1 = 910;
    return s1 + s2 > s2 + s1;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string>vec;
    /*숫자와 숫자를 비교하여 정렬하면 numbers가 9,10 인 경우 10이 더 크므로 109가 정답이 된다.
      각 숫자의 자릿수가 다르므로 일일히 이어붙여가며 비교하기에는 비효율적이다.
      숫자를 문자열로 바꾸어 더해주면 쉽게 이어붙여서 비교가 가능하다.*/
    for(int i{0}; i < numbers.size(); i++) {
        vec.push_back(to_string(numbers[i]));
    }
    sort(vec.begin(),vec.end(),cmp);
    for(int i{0}; i < vec.size(); i++) {
        if(vec[0] == "0"){
            /*numbers가 [0,0,0,0...]인 경우*/
            answer = "0";
            break;
        }
        answer += vec[i];
    }
    return answer;
}
