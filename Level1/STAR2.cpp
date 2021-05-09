#include <iostream>

using namespace std;

int main() {

	int n=0,i=0,j=0;

	cin>>n;

	for (i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++)
			cout<<" ";

		for (j = 1; j <= i; j++)
			cout<<"*";
		cout<<endl;
	}
}
