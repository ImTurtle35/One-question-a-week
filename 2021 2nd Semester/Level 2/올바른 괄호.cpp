#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<char> stk;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]==')'){
            stk.push(s[i]);
        }
        else if(s[i]='('){
            if(stk.empty()){
                answer=false;
                break;
            }
            stk.pop();
        }
    }
    if(!stk.empty()){
        answer=false;
    }
    cout<<stk.size();
    return answer;
}
