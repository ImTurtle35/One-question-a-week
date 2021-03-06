#include <string>
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;



class sol
{
public:
	vector<string> operations;
	list<int> data0;

	sol(vector<string> oper1)
	{
		operations = oper1;


		for (int s_n = 0; s_n < operations.size(); s_n++)
		{
			//cout << operations[s_n].at(0) << endl;
			
			if (operations[s_n].at(0) == 'D' && data0.size() > 0) //삭제연산, 리스트 크기 !=0
			{
				if (operations[s_n].at(2) == '1')//최댓값 삭제
				{
					data0.erase(max_element(data0.begin(), data0.end()));
				}

				else //최솟값 삭제
				{
					data0.erase(min_element(data0.begin(), data0.end()));
				}
			}


			else if (operations[s_n].at(0) == 'I') //삽입연산
			{
				if (operations[s_n].at(2) == '-') //음수인 경우
				{
					int leno = operations[s_n].length() - 1;
					string ex_data = operations[s_n].substr(3, leno);

					//cout << stoi(ex_data) << endl;
					data0.push_back(-stoi(ex_data));

				}

				else {//양수인 경우

					int leno = operations[s_n].length() - 1;
					string ex_data = operations[s_n].substr(2, leno);
					//cout << stoi(ex_data) << endl;
					data0.push_back(stoi(ex_data));
				}

			}
		}


		showing_list();
	}


	void showing_list()
	{
		for (list<int>::iterator i_n = data0.begin(); i_n != data0.end() ; i_n++)
		{
			cout << *i_n << " ";
		}

		cout << endl;
	}


};





vector<int> solution(vector<string> operations) {
	vector<int> answer;



	return answer;
}


vector<string>  alpa = { "I 7", "I 5", "I -5", "D -1" };



void main(void)
{
	sol *sol1 = new sol(alpa);
	system("pause");
}







