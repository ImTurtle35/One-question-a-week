#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

map<int, int> all_data;
int answer = 0;

void make_num(int data, int index, int size , string numbers)
{
    numbers[index] = 'x';
    int index_a = index;

    if (size < numbers.length())
        for (int x = size; x < numbers.length(); x++)
        {            
            do
            {
             index_a++; index_a = index_a >= (numbers.length()) ? index_a - numbers.length() : index_a;
            }while (numbers[index_a] == 'x');

            int data_a = (int)(pow(10, size)) * (int)(numbers[index_a] - '0') + data;
            make_num(data_a, index_a, size + 1, numbers);
        }

    if (all_data.find(data) == all_data.end()) {
     
        if (data <= 1) return;
        all_data.insert(pair<int, int>(data, 1));

        for (int x = 2; x <= sqrt(data); x++)
            if (data % x == 0)
                return;
        answer++;
    }         
}

int solution(string numbers) {
    
    vector<int> data_list;
    
    for (int x = 0; x < numbers.length(); x++) 
        make_num(int(numbers[x] - '0'), x, 1, numbers);
                   
    return answer;
}

string a = "17";
int main(void)
{
    solution(a);
    return 0;
}
