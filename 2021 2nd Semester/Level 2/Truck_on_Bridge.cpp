#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue <int> q;
    int answer = 0; // 걸리는 시간
    int bridgetruck=0; // 다리위에 있는 트럭의 무게
    int i=0; 
    
    while(1){
        
        answer++; // while문이 반복되는 동안 계속 1씩 증가
        
        // queue의 크기가 다리의 길이와 같아지는 경우 = 트럭이 다리를 다 지났을 때
        if(q.size()==bridge_length){
            bridgetruck-=q.front(); // 다리 위 트럭의 무게에서 다 건넌 트럭의 무게 빼기
            q.pop(); // 다리위의 트럭에서 빼내기
        }
        
        // 새로 트럭이 올라왔을 때 전에 있던 트럭의 무게와 합한 것이 weight를 넘지 않을 경우
        if(bridgetruck+truck_weights[i]<=weight){
            
            if(i==truck_weights.size()-1){ // 트럭이 더이상 없을 경우
                answer+=bridge_length; // 마지막 트럭의 bridge_length 더해주기
                break; // 반복문 끝내기
            }
            
            q.push(truck_weights[i]); // 새로운 트럭 넣어주기
            bridgetruck+=truck_weights[i]; // 새로운 트럭 무게 bridgetruck에 더해주기
            i++;
        }
        
        //트럭의 무게가 weigth를 넘을 경우
        else{
            q.push(0); // 도착점으로 만들기
        }
    }
    return answer;
}

