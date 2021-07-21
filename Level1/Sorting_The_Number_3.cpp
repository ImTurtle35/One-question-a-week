#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int arr[10001]={0,};
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        arr[x-1]++;
    }
    for(int i=0;i<10001;i++){
        for(int j=0;j<arr[i];j++){
            cout<<i+1<<"\n";
        }
    }
}
