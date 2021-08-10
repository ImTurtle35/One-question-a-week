#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;

    for (int x = 0; x < clothes.size(); x++)
    {
        if (m.find(clothes[x][1]) == m.end())
            m.insert(pair<string, int>(clothes[x][1], 1));

        else
            m.find(clothes[x][1])->second += 1;
    }

    for (auto i = m.begin() ; i != m.end() ; i++)
        answer *= (i->second + 1);

    answer -= 1;
    return answer;
}

vector<vector<string>> data0 = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};

int main(void)
{
  solution(data0);
  return 0;
}
