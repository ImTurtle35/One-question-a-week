#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;



class sol
{
public:
	vector<vector<string>> tickets;
	list<string> answer0;
	vector<string> answer00;
	const string ICN = "ICN";
	
	int size = 0;
	


	static bool cmp(const vector<string> &a1, const vector<string> &a2)
	{			
		return (a1[0] > a2[0]);
	}

	static bool cmp2(const vector<string> &a1, const vector<string> &a2)
	{
		if (a1[0] == a2[0])
			return a1[1] > a2[1];

		else return false;
	}

	void dfs(list<string> answer)
	{	
		vector<string> exe1;
	 
		if (answer.size() > tickets.size())
		{			
				//print2(answer);  //delete some time

				if (answer0.size() == 0 || answer0 > answer)
					answer0 = answer;

				return;
		}


		for (int x_p = tickets.size() - 2 ; x_p >= 0; x_p--)
		{
			if (answer.back() == tickets[x_p][0]) {
				exe1 = tickets[x_p];

				tickets[x_p][0] = "";
				tickets[x_p][1] = "";

				//print2(answer);
				//cout << start[0] << " " << start[1] << endl;
				//cout << exe1[0] << " 1 " << exe1[1] << endl;

				answer.push_back(exe1[1]);
				dfs(answer); //깊이로 파고든다.
				answer.pop_back();

				tickets[x_p][0] = exe1[0];
				tickets[x_p][1] = exe1[1];
			}
		}	
	}

	sol(vector<vector<string>> tickets2)
	{
		sort(tickets2.begin(), tickets2.end(), cmp);
		sort(tickets2.begin(), tickets2.end(), cmp);

		for (int x = 0; x < tickets2.size(); x++)
		{
			if (tickets2[x][0] != ICN) 
				tickets.push_back(tickets2[x]);
			
		}

		for (int x = 0; x < tickets2.size(); x++)
		{
			if (tickets2[x][0] == ICN)
				tickets.push_back(tickets2[x]);
		}


		int size = tickets.size()-1;
		//print();
		


		while (tickets[size][0] == ICN && size >= 0)
		{
			vector<string> exe1 = tickets[size];

			list<string> alpa;
			alpa.push_back(exe1[0]);
			alpa.push_back(exe1[1]);

			tickets[tickets.size() - 1][0] = "";
			tickets[tickets.size() - 1][1] = "";

			dfs(alpa);

			tickets[tickets.size() - 1][0] = exe1[0];
			tickets[tickets.size() - 1][1] = exe1[1];

			size--;
		}

		for (list<string>::iterator x = answer0.begin(); x != answer0.end(); x++)
		{
			answer00.push_back(*x);
		}	

		print2(answer0);
	}



	void print()
	{
		for (int x_p = 0; x_p < tickets.size(); x_p++)
		{
			for (int y_p = 0; y_p < tickets[0].size(); y_p++)
			{
				cout << tickets[x_p][y_p] << " ";
			}

			cout << endl;
		}
	}


	void print2(list<string> answer0)
	{
		for (list<string>::iterator x_p = answer0.begin(); x_p != answer0.end(); x_p++)
		{
			cout << *(x_p) << " ";
		}
		cout << endl;
	}


};


vector<string> solution(vector<vector<string>> tickets) {
	
	sol *sola = new sol(tickets);	
	vector<string> answer = sola->answer00;
	return answer;
}


vector<vector<string>> test1 = { {"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL", "SFO"}};

void main(void)
{
	sol *solb = new sol(test1);
	system("pause");
}

