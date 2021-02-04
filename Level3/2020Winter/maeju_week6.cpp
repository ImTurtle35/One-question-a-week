#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;


class solve{
	public:
		int n;
		int checker_size = 0;
		vector<int> times;
		vector<unsigned long long> mai_data;
		unsigned long long answer_time = 0;
		unsigned long long test_time = 0;
		int vir_data = 0; //가상 데이터


		int howmany_check(int time_a) //time_a 시간동안 얼마나 체크하는 지 return
		{
			int return_time = 0;

			for (int x_p = 0; x_p < times.size(); x_p++)
			{
				return_time += (time_a / times[x_p]) ;
			}

			return return_time;
		}


	solve(int n2, vector<int> times2)
	{
		n = n2;
		times = times2;
		sort(times.begin(), times.end());
		mai_data.assign(2, 0);
		mai_data[0] = 1; //
		mai_data[1] = times[times.size()-1] * n; //최악의 수행시간을 넣는다.

			//최악의 수행시간 부터 검사

		
		while(mai_data[0] <= mai_data[1])
		{
			cout << "mai 1 " << mai_data[1] << endl;
			cout << "test_data " << test_time << endl;
			cout << "mai 0 " << mai_data[0] << endl;
			cout << "howma" << howmany_check(test_time) << endl;

			test_time = (mai_data[1] + mai_data[0]) / 2;

			if (howmany_check(test_time) >= n) //시간이 과한 경우
			{
		
				if (answer_time == 0) answer_time = test_time;

				else if (answer_time > test_time) answer_time = test_time;
				mai_data[1] = test_time - 1; //이하동문
			}


			else //시간이 부족한 경우
			{
				mai_data[0] = test_time + 1;		
			}

	
			//else test_time = (mai_data[1] + mai_data[0])/2; //계속 중간을 탐색

		}

		

		//cout << "answer " << answer_time << endl;
		//print();

		//sort(times.begin(), times.end(), [](const vector<unsigned long long>& x1, const vector<unsigned long long>& x2) { if (x1[0] < x2[0]) { return x1[0] < x2[0]; } else return x1[1] < x2[1]; });

		//times.assign(times2.begin(), times2.end()); //unsigned long long으로 옮긴다.
		//sort(times.begin(), times.end(), greater<int>()); //큰 순서대로 정렬

	}

	static bool compare1(vector<unsigned long long>& x1, vector<unsigned long long>& x2)
	{
		if (x1[0] < x2[0]) {
			return x1[0] < x2[0];
		}

		else return 0;
		//else return x1[1];
	}

	static bool compare2(vector<unsigned long long>& x1, vector<unsigned long long>& x2)
	{
		if (x1[1] < x2[1]) {
			return x1[1] < x2[1];
		}

		else return 0;
		//else return x1[1];
	}


	/*
	void print()
	{
		for (vector<vector<unsigned long long>>::iterator x_p = times.begin(); x_p != times.end(); x_p++)
		{
			for (vector<unsigned long long>::iterator y_p = x_p->begin(); y_p != x_p->end(); y_p++)
			{
				cout << *y_p << " ";
			}

			cout << endl;
		}

		cout << endl;
	}
	*/

};


unsigned long long solution(int n, vector<int> times) {

	solve* sol1 = new solve(n, times);


	unsigned long long answer = sol1->answer_time;
	return answer;
}

int n = 6;
vector<int> times = {7, 10};

int main(void)
{
	solve* sol2 = new solve(n, times);
	//sol2->print();
	system("pause");

	return 0;
}