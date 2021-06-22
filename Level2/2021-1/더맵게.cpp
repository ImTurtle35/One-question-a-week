#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void print(vector<int>& sco1)
{
    for (vector<int>::iterator x = sco1.begin(); x != sco1.end(); x++)
    {
        cout << *x << " ";
    }

    cout << endl;
}

int solution(vector<int> scoville, int K) {
    int answer = 0;
    make_heap(scoville.begin(), scoville.end(),greater<int>());
    //print(scoville);

    while (scoville.size() > 1) {
        pop_heap(scoville.begin(), scoville.end(),greater<int>());

        int k1 = scoville.back();
        if (k1 >= K){break;}
        scoville.pop_back();
        
        pop_heap(scoville.begin(), scoville.end(), greater<int>());
        int k2 = scoville.back();
        scoville.pop_back();

        scoville.push_back(k1 + 2 * k2);
        answer++;
        push_heap(scoville.begin(), scoville.end(), greater<int>());
        //print(scoville);
    }

    if (scoville.size() > 0)
    {
        pop_heap(scoville.begin(), scoville.end(), greater<int>());
        int last_k = scoville.back();

        if (last_k < K) { answer = -1; }
    }

    return answer;
}

vector<int> a1 = { 1, 2, 3, 9, 10, 12 };
int k1 = 7;

int main(void)
{
    solution(a1, k1);
    return 0;
}
