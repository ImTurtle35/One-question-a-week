#include <string>
#include <vector>
#include <iostream>
using namespace std;


class sol
{
public:
    int len = 1;
    int comp = 3;
    int comp_0 = 3;
    string answer0 = "";
    string answer = "";

    void push_back0(int n)
    {
        if (n == 0)
            answer0.push_back('1');

        else if (n == 1)
            answer0.push_back('2');

        else
            answer0.push_back('4');
    }

    sol(int n)
    {

        while (n >= 0)
        {
            n = n - 1;

            push_back0(n % 3);
            n /= 3;

            if (n <= 0)
                break;
        }

        for (int x = answer0.length() - 1; x >= 0; x--)
        {
            answer.push_back(answer0[x]);
        }
    }
};

string solution(int n) {

    string answer = (new sol(n))->answer;
    return answer;
}

string test = "(())()()";


int main() {

    while (true)
    {
        int n;
        cin >> n;
        cout << solution(n) << endl;
    }


    return 0;
}
