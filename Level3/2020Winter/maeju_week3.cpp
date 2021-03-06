#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <list>
using namespace std;

class sol
{
public:

	//routes -> 0 : 진입시점 , 1 : 나간시점
	// -30000 <= 진입,진출 <= 30000
	//모든 차량이 한 번은 단속용 카메라 만나
	//차량의 대수는 1대 이상 10000대 이하
	list<list<int>> routes2;
	int answer = 0;

	sol(vector<vector<int>> routes)
	{	
		sort(routes.begin(), routes.end(), [](const std::vector<int>& a, const std::vector<int>& b) {return(a[1] < b[1]); }); //빨리 벗어나는 대로
		routes2.assign(routes.size(), list<int>(2));

		for (int row = 0; row < routes.size(); row++)
		{	
			list<list<int>>::iterator alpa = routes2.begin();
			advance(alpa, row);

			for (int col = 0; col < 2; col++)
			{
				list<int>::iterator beta = alpa->begin();
				advance(beta, col);

				*beta = routes[row][col];
			}		
		}//혹시 시간이 부족할까 하여 리스트로 옮겼다.

		
		while (routes2.size() > 0) {

			list<list<int>>::iterator alpa = routes2.begin();
			list<int>::iterator beta = alpa->begin();
			advance(beta, 1);

			int checking_data = *beta;

			for (list<list<int>>::iterator row = routes2.begin(); row != routes2.end();)
			{
				list<int>::iterator col_x = row->begin();
				int axis_x = *col_x;
				advance(col_x, 1);

				int axis_y = *col_x;

				if (axis_x <= checking_data && axis_y >= checking_data)
				{
					routes2.erase(row++);
				}

				else row++;
			} //모든 차량을 치워야 함으로, 해당 목록에서 가장 도로를 빨리 벗어나는 차의 위치가 첫번째 카메라의 위치이다.
			  //그 다음 없애지 못한 차들 기준으로 가장 빨리 벗어나는 차가 두 번째 카메라의 위치이다.

			answer++;
		}

			
		cout << answer << endl;
	}

	void print2()
	{
		for (list<list<int>>::iterator row = routes2.begin(); row != routes2.end(); row++)
		{
			for (list<int>::iterator col = row->begin(); col != row->end(); col++)
			{
				cout << *col << " ";
			}

			cout << endl;
		}

		cout << endl;
	}

};



int solution(vector<vector<int>> routes) {
	
	sol* sol1 = new sol(routes);
	
	
	int answer = sol1->answer;
	return answer;
}


vector<vector<int>> example1 = {{-20, 15}, {-14, -5},{-18, -13},{-5, -3} };


int main(void)
{
	sol* sol1 = new sol(example1);
	system("pause");
}