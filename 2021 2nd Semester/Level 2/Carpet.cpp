#include <string> 
#include <vector> 
#include <iostream> 
using namespace std; 
vector<int> 
solution(int brown, int yellow) { 
 vector<int> answer; 
 for(int y = 1; y < 2500; y++) 
   { for(int x = 1; x < 2500; x++) 
     { if((brown - 4) / 2 == x + y && yellow == x * y) 
       { if (x >= y) 
         { answer.push_back(x + 2); 
           answer.push_back(y + 2); 
           return answer; 
         } 
         else 
           { 
             answer.push_back(y + 2);
             answer.push_back(x + 2); 
             return answer; 
           }
         } 
       } 
     }
     return answer; 
  }
