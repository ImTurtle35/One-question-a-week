#include<iostream>

using namespace std;

int main(void)
{
    int a, i, Max, Min;
    cin >> a;
    int A[1000000] = { 0 };

    for (i = 0; i < a; i++)
    {
        cin >> A[i];
    }
    Max = A[0];
    Min = A[0];
    for (i = 0; i < a; i++)
    {
        if (Max < A[i])
        {
            Max = A[i];
        }
    }
    for (i = 0; i < a; i++)
    {
        if (Min > A[i])
        {
            Min = A[i];
        }
    }
    cout << Min <<" " << Max;
    return 0;
}
