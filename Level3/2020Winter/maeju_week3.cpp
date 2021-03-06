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

	//routes -> 0 : ���Խ��� , 1 : ��������
	// -30000 <= ����,���� <= 30000
	//��� ������ �� ���� �ܼӿ� ī�޶� ����
	//������ ����� 1�� �̻� 10000�� ����
	list<list<int>> routes2;
	int answer = 0;

	sol(vector<vector<int>> routes)
	{	
		sort(routes.begin(), routes.end(), [](const std::vector<int>& a, const std::vector<int>& b) {return(a[1] < b[1]); }); //���� ����� ���
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
		}//Ȥ�� �ð��� �����ұ� �Ͽ� ����Ʈ�� �Ű��.

		
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
			} //��� ������ ġ���� ������, �ش� ��Ͽ��� ���� ���θ� ���� ����� ���� ��ġ�� ù��° ī�޶��� ��ġ�̴�.
			  //�� ���� ������ ���� ���� �������� ���� ���� ����� ���� �� ��° ī�޶��� ��ġ�̴�.

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