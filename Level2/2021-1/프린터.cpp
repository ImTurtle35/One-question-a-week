#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int print = 0;
int get_wanting = 0;
int location = 0;
vector<int> priorities;


//--------------
void print2()
{
	for (vector<int>::iterator x = priorities.begin(); x != priorities.end(); x++)
	{
		cout << *x << " ";
	}

	cout << endl;
}

void arrange(int max)
{	
	while(priorities.front() < max)
	{
		if (priorities.size() <= 0) throw string("size error");
		//print2();

		if (location == 0)
		{
			priorities.push_back(priorities.front());
			priorities.erase(priorities.begin());
		    location = priorities.size() - 1;
		}

		else
		{
			priorities.push_back(priorities.front());
			priorities.erase(priorities.begin());
			location--;
		}

		if (location < 0) throw location;
	}

	priorities.erase(priorities.begin());
	location--;
}



int solution(vector<int> priorities0, int location0) {

	try {
	
		get_wanting = priorities0[location0]; //for find
		location = location0;
		priorities.assign(priorities0.begin(), priorities0.end());
		//throw string("hehe");
	
		while (priorities.size() > 0) {
			vector<int>::iterator max_index = max_element(priorities.begin(), priorities.end()); //where it	
	
			if (max_index - priorities.begin() < 0) throw *max_index;

			if (location == max_index - priorities.begin())
			{
				print++;
				break;
			}

			else
			{
				print++;
				arrange(*max_index);
			}
		}

	}

	catch (exception e)
	{
		cerr << "error error" << endl;
		cerr << e.what() << endl;
	}

	catch (int except) {

		cerr << "Error about " << except << endl;
	}

	catch(string except){
		cerr << "error about " << except << endl;
	}

    int answer = print;
	//cout << answer << endl;
    return answer;
}


vector<int> data1 = { 2, 1, 3, 2 };
vector<int> data2 = { 1, 1, 9, 1, 1, 1 };

int main(void)
{
	//cout << solution(data1, 2) << endl;
	cout << solution(data2, 0) << endl;

	system("pause");
}
