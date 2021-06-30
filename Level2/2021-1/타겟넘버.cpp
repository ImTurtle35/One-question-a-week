#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(vector<int> numbers, int target) {

    vector<int> list_a;
    list_a.push_back(target);
    
    int index_s = 0;
    int index_l = 0;
    int answer = 0;

    for (int x = 0; x < numbers.size(); x++)
    {
        int index_s0 = list_a.size();
        
        for (int y = index_s; y <= index_l; y++)
        {
            list_a.push_back(list_a[y] - numbers[x]);
            if (x == numbers.size() - 1 && list_a.back() == 0)
                answer++;

            list_a.push_back(list_a[y] + numbers[x]);
            if (x == numbers.size() - 1 && list_a.back() == 0)
                answer++;
        }

        index_s = index_s0;
        index_l = list_a.size()-1;
    }
    
    //cout << answer << endl;
    return answer;
}


int main(void)
{
    return 0;
}
