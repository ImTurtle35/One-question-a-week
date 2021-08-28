#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;

    sort(citations.begin(), citations.end(), greater<int>());
    //제일 큰 값이 0이면 H-Index가 0이다

    for (int i = 0; i < citations.size(); i++)
    {
        if (citations[i] >= (i + 1))
            answer++;
    }

    return answer;
}