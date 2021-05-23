#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> answer0;
vector<int> answer00;
vector<int> answer;
int size0 = 0;
int indexX = 0;
int indexY = 0;
int data0 = 1;


void print()
{
	for (int x = 0; x < answer0.size(); x++)
	{
		for (int y = 0; y < answer0[x].size(); y++)
		{
			//cout << answer0[x][y] << " ";
			answer.push_back(answer0[x][y]);
		}
		//cout << endl;
	}
}

void making_data()
{
	if (size0 > 0)
		for (int x = 0; x < size0; x++)
		{
			answer0[indexX][indexY] = data0;
			data0++;

			indexX++;
		}

	size0--; //왼쪽

	indexX--;
	indexY++;
	data0--;

	if (size0 > 0)
		for (int x = 0; x < size0; x++)
		{
			data0++;

			answer0[indexX][indexY] = data0;
			indexY++;
		}

	size0--; //아래


	indexX--;
	indexY--;
	indexY--;

	if (size0 > 0)
		for (int x = 0; x < size0; x++)
		{
			data0++;

			answer0[indexX][indexY] = data0;

			//print();

			indexX--;
			indexY--;
		}

	//오른쪽
	size0--;
	indexX++;
	indexX++;
	indexY++;
	data0++;
}


vector<int> solution(int n) {
	size0 = n;

	for (int x = 1; x <= n; x++) //2array vector
	{
		vector<int> data;
		data.assign(x, 0);
		answer0.push_back(data);
	}

	while (size0 > 0) {
		making_data();
	}
	
	print();
	return answer;
}



int main(void)
{
	system("pause");
	return 0;
}
