#include <string>
#include <vector>
#include<algorithm>
using namespace std;

bool answer = true;

bool comp(const string& s1, const string& s2) {
    if (s1.length() >= s2.length()) {
        if (s2 == s1.substr(0, s2.length()))
            answer = false;

        return s1 < s2;        
    }

    else{
        if (s1 == s2.substr(0, s1.length()))
            answer = false;

        return s1 < s2;
    } 
}

bool solution(vector<string> phone_book) {
    
    sort(phone_book.begin(), phone_book.end(), comp);
    return answer;
}

vector<string> phone_book0 = { "119", "97674223", "1195524421" };

int main(void)
{
    solution(phone_book0);
    return 0;
}
