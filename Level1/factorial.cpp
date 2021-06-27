#include <iostream>
using namespace std;

int factorial(int N)
{
    if(N<=1)
        return 1;
    else
    {
        return N*factorial(N-1);
    }
}

int main(void)
{
    int N;
    cin>>N;
    
    cout<<factorial(N)<<endl;
    
    return 0;
}
