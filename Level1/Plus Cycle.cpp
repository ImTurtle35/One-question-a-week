#include<iostream>

using namespace std;

int main(void)
{
    int a, b, k = 0,  n = 0, i = 0;

    cin >> n;
    k = n;

    while (1)
    {
        if (k < 10)//십의 자리를 0으로 해주는!
        {
            a = 0;
            b = k;
        }
        a = k / 10;//10의 자리
        b = k % 10;//1의 자리
        k = (b * 10 + (a + b) % 10);//새로운 k값 연산!
        i++;//일부러 여기에 i를 1씩 더해준다
        //그 이유는 최종과정에서 n과 k가 일치할때도 1사이클로 치기 때문
        if (n != k)//같은지 같지 않은지 구별해줌
        {
            continue;
        }
        else
            break;
    }
    cout << i << endl;
    return 0;
}
