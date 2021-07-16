#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
    stack<int> s0;
    int answer = 0;

    if (s.length() == 0) //string size = 0
        return 0;

    else
     s0.push(s[0]);

    for (int x = 1; x < s.length(); x++)
    {
        if(s0.empty()) s0.push(s[x]);

        else if(s[x] == s0.top())
            s0.pop();

        else
            s0.push(s[x]);
    }

    if (s0.size() > 0)
        return 0;

    else return 1;
}

string a = "baabaa";

int main(void)
{
    cout << solution(a) << endl;
    return 0;
}
