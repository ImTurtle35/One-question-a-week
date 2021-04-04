#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int bridge_length0;
int weight0;
deque<int> truck_weights0;


int solution(int bridge_length, int weight, vector<int> truck_weights) {
  
    bridge_length0 = bridge_length;
    weight0 = weight;

   truck_weights0.resize(truck_weights.size());
   copy(truck_weights.begin(), truck_weights.end(), truck_weights0.begin());
   deque<int> truck_weight1 = deque<int>(bridge_length0, 0);

    int current_weight = 0;
    int current_counter = 0;
    int answer =0;
    int x = 0;

    
    while (truck_weights0.size() > 0 || current_weight > 0)
    {
      
        if (truck_weights0.size() > 0)
        {
            current_weight -= truck_weight1.back();
            truck_weight1.pop_back();
            
            if (current_weight + truck_weights0.front() <= weight0) {
                current_weight += truck_weights0.front();
                truck_weight1.push_front(truck_weights0.front());
                truck_weights0.pop_front();              
            }

            else
                truck_weight1.push_front(0);             
            
        }

        else
        {
            current_weight -= truck_weight1.back();
            truck_weight1.pop_back();
                        
            truck_weight1.push_front(0);     
             
        }

        answer++;
    }

    return answer;
}


int bridge_length_t = 4;
int weigth_t = 2;
vector<int> truck_weights_t = {1,1,1,1};


int main(void)
{
    cout << solution(bridge_length_t, weigth_t, truck_weights_t);
    return 0;
}
