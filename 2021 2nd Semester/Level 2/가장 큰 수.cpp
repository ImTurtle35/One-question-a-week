#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
bool compare(string a, string b) {
    return a + b > b + a;
}
 
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;
    
    for (auto num : numbers)
        temp.push_back(to_string(num));
    
    sort(temp.begin(), temp.end(), compare);
    
    if (temp.at(0) == "0")        
        return "0";
    
    for (auto num : temp)
        answer += num;
    return answer;
}
