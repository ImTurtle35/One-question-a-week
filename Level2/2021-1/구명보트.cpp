#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

class sol
{

public:
    list<int> people;
    int limit;
    int answer = 0;

    int start;
    int end;


    sol(vector<int> people0 , int limit0)
    {
        int start = 0;
        int end = people0.size() - 1; \
        limit = limit0;

        sort(people0.begin(), people0.end(), greater<int>());

        while (start <= end) {

           //cout << people0[start] << " " << people0[end] << endl;
            
            if (people0[start] + people0[end] <= limit)
            {
                answer++;
                start++;
                end--;
            }

            else
            {
                start++;
                answer++;
            } 
        }
      
        //cout << answer << endl;
    }

    void print()
    {
        for (list<int>::iterator  x = people.begin() ; x != people.end(); x++)
        {
            cout << (*x) << " ";
        }

        cout << endl;
    }
};


using namespace std;

int solution(vector<int> people, int limit) {

    sol* sola = new sol(people, limit);


    int answer = sola->answer;
    return answer;
}


vector<int> t_people = {70,80,50};

int t_limit = 100;


int main(void)
{
    sol* sola = new sol(t_people, t_limit);

    cout << sola->answer;

    return 0;
}
