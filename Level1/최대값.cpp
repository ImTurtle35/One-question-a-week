#include <iostream>

using namespace std;

int main()
{
	int arr[9], max = 0, a = 0;

	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		if (max < arr[i])
		{
			max = arr[i];
			a = i + 1;
		}
	}
	cout << max << endl << a;
	return 0;
}
