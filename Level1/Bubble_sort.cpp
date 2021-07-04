#include <iostream>

using namespace std;

int main() {
    int A;
    int arr[1000] = {0,};
    int temp;
    
    cin >> A;
    
    for(int i = 0; i < A; i++)
        cin >> arr[i];
    
    for(int i = A; i > 1; i--)
        for(int j = 0; j+1 < i; j++)
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
    
    for(int i = 0; i < A; i++)
        cout << arr[i] << '\n';
}
