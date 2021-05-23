#include <string>
#include <vector>
#include <iostream>

using namespace std;

class solute{

	public:
	
	vector<vector<int>> answer0;
	vector<int> answer00;
	vector<int> answer;
	
	int data = 1;
	int size;
	int n;
	int indexX = 0;
	int indexY = 0;



	void making_data()
	{
		if(size > 0)
			for (int x = 0 ; x < size ; x++)
			{
				answer0[indexX][indexY] = data;
				data++;

				indexX++;	
			}

		size--; //왼쪽

		indexX--;
		indexY++;
		data--;

		if (size > 0)
			for (int x = 0; x < size; x++)
			{
				data++;

				answer0[indexX][indexY] = data;
				indexY++;
			}

		size--; //아래


		indexX--;
		indexY--;
		indexY--;

		if (size > 0)
			for (int x = 0; x < size; x++)
			{
				data++;

				answer0[indexX][indexY] = data;

				//print();

				indexX--;
				indexY--;
			}

		//오른쪽
		size--;
		indexX++;
		indexX++;
		indexY++;
		data++;
	}


	solute(int n0)
	{
		int x = 0;
		size = n0;
		int n = n0;

		for (int x = 1; x <= n0; x++)
		{
			vector<int> data;
			data.assign(x, 0);

			answer0.push_back(data);
		}

		int indexX = 0;
		int indexY = 0;

		while (size > 0) {
			making_data();
		}
	
		print();
	}

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

};


vector<int> solution(int n) {
	vector<int> answer;
	solute *sol = new solute(n);

	return sol->answer;
}



int main(void)
{
	solute *sol1 = new solute(5);
	//sol1->print();
	system("pause");
	return 0;
}
