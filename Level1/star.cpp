#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    int i;
    int k;
    cin>>a>>b;
    for(i=1;i<=b;i++){
        for(k=1;k<=a;k++)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}
