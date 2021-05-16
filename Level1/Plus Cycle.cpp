#include<iostream>

using namespace std;

int main(void)
{
    int a, b, k = 0, tempk, n = 0, i = 0, result = 0;

    cin >> n;
    k = n;

    while (1)
    {
        if (k < 10)
        {
            a = 0;
            b = k;
        }
        a = k / 10;
        b = k % 10;
        tempk = (a + b) % 10;
        k = (b * 10 + tempk);
        i++;
        if (n != k)
            continue;
        else
            break;
    }
    cout << i << endl;
    return 0;
}
