#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int small_len = 0;
string s;

int calcul_len(int size)
{
    int data_len = 0;
    string s1 = s;
    string::size_type index_0 = 0;

    while (s1.length() >= size)
    {
        if (size > s1.length()) throw string("cl_error1");
       
        string find0 = s1.substr(0,size);
        s1 = s1.substr(size);
        string::size_type pos0 = s1.find(find0);
        
        if (pos0 == 0) //같은 게 또 있을 때
        {
            int count_0 = 1;
            data_len += size;

            while (pos0 == 0)
            {
                s1 = s1.substr(size);
                pos0 = s1.find(find0);
                count_0++;
            }

            data_len += ((int)log10(count_0)+1); //갯수가 두 자리 수 일 때
        }

        else
            data_len += size;
    }


    if (s1.length() > 0) data_len += s1.length(); //나머지가 있을 때
    return data_len;
}


int solution(string s0){

    try {
        s = s0;
        small_len = s.length(); //original size
        
        for (int x = 1; x <= s.length(); x++)         
         if (calcul_len(x) < small_len) small_len = calcul_len(x);       
    }

    catch (exception e) {
        cerr << e.what() << endl;
    }

    catch(string exce1){
        cerr << "error " << exce1 << endl;
    }

    catch (int exce2) {
        cerr << "Error " << exce2 << endl;
    }

    int answer = small_len;
    return answer;
}

string a = "aabbaccc";
string b = "ababcdcdababcdcd";
string c = "abcabcdede";
string d = "abcabcabcabcdededededede";
string e = "xababcdcdababcdcd";
string f = "aaaaaaaaaad";
string g = "aaaaaaaaaa";
string h = "abcdefgh";

int main(void)
{
    cout << solution(h) << endl;
    return 0;
}
