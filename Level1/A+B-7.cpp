#include <iostream>

using namespace std;

int main(void)
{
	int a, b, T, i;

	cin >> T;

	for (i = 0; i < T; i++)
	{
		cin >> a >> b;
		cout << "Case #" << i + 1 << ": " << a + b << endl;
	}
	return 0;
}
