#include <string>
#include <vector>
using namespace std;


class sol
{
public :
    vector<int> answer00;
    vector<int> answer0;
    int end_task = 100;
 

    sol(vector<int> progresses, vector<int> speeds)
    {
        for (int x = 0; x < progresses.size(); x++)
        {
            int left_task = end_task - progresses[x];

            if (left_task % speeds[x] == 0)
                answer00.push_back(left_task / speeds[x]);

            else
                answer00.push_back((left_task / speeds[x]) + 1);

        }//answer00 완성

        int basis_day = answer00[0];
        int basis_task = 1;


        for (int x = 1; x < answer00.size(); x++)
        {
            if (basis_day >= answer00[x])
                basis_task++;
           
            else
            {
                answer0.push_back(basis_task);
                basis_day = answer00[x];
                basis_task = 1;
            }
        }

        answer0.push_back(basis_task);
    }
};

vector<int> solution(vector<int> progresses, vector<int> speeds){

    vector<int> answer = (new sol(progresses, speeds))-> answer0;
    return answer;
}


string test = "(())()()";

int main() {
    
  
    return 0;
}
