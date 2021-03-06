#include <string>
#include <vector>
#include <iostream>

using namespace std;


class sol
{
public:
	vector<vector<int>> triangle;
	int return_value = 0;

	sol(vector<vector<int>> &triangle0)//#1 test print
	{
		triangle = triangle0; //여기 까지는 시간 error no
		test(0);
	
		cout << return_value << endl;
	}

	void test(int x_p)
	{

		int x2_p = x_p + 1;

		if (x2_p < triangle.size()) {

			triangle[x2_p][0] += triangle[x_p][0]; //물려받을 부모가 0뿐인 경우

			for (int y2_p = 1 ; y2_p <= x2_p-1; y2_p++){ //물려받을 부모가 1~n-1

				if (triangle[x_p][y2_p-1] > triangle[x_p][y2_p])
				{
					triangle[x2_p][y2_p] += triangle[x_p][y2_p-1];					
				}

				else
				{
					triangle[x2_p][y2_p] += triangle[x_p][y2_p];
				}
			}

			triangle[x2_p][x2_p] += triangle[x_p][x2_p - 1]; //물려받을 부모가 n인경우
 
			return test(x_p + 1);
		}


		else //최종값 찾음
		{
			for (int y_p = 0; y_p <= x_p; y_p++)
			{
				return_value = (return_value >= triangle[x_p][y_p]) ? return_value : triangle[x_p][y_p];
			}
		}
	}




	void test_print() //#1 test print
	{
		for (int x_p = 0; x_p < triangle.size(); x_p++)
		{
			for (int y_p = 0; y_p < triangle[x_p].size(); y_p++)
			{
				cout << triangle[x_p][y_p] << " ";
			}

			cout << endl;
		}

	}
};


vector<vector<int>> exam1 = { {7},{3, 8},{8, 1, 0},{2, 7, 4, 4},{4, 5, 2, 6, 5} };
vector<vector<int>> exam2 = { { 7 },{ 3, 8 }};

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	sol* sol1 = new sol(exam1);
	answer = sol1->return_value;

	return answer;
}


int main(void)
{

	sol* sol1 = new sol(exam1);
	system("pause");
	return 0;
}