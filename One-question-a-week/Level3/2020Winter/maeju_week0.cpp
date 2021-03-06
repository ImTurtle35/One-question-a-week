#include <string>
#include <vector>
#include <iostream>

using namespace std;


class solve 
{
	public:
		vector<vector<int>> key; //key, 2차원 벡터
		vector<vector<int>> lock; //lock, 2차원 벡터
		
		int key_s = 0; //key의 한 변 길이
		int lock_s = 0; //lock의 한 변 길이

		int lock_nut = 0;
		bool answer = false;

		void print_view()
		{
			showing_graph(key);
			cout << endl;
			showing_graph(lock);
			cout << endl;
		}


	solve(vector<vector<int>> key0, vector<vector<int>> lock0)
	{	
		key_s = key0.size();
		lock_s = lock0.size();

		this->key = key0;
		this->lock = lock0;

		for(int x_pos = 0 ; x_pos < lock_s ; x_pos++) //lock의 홈 부분을 찾는다, lock_nut는 홈의 개수
			for (int y_pos = 0 ; y_pos < lock_s ; y_pos++)
			{
				if (lock[x_pos][y_pos] == 0)
					lock_nut++;
			}


		for (int count = 0; count < 5; count++)
		{
			print_view();

			if (find_key() == true){
				this->answer = true;
				return;
			}

			else
				turnRight90();
		}


	}


	bool sub_find_key(int x_pos, int y_pos) //key를 여러 형태로 변화, 90도 돌린다던지 등등.......
	{
		int match_nut = 0;

		for (int x_pos_key = 0; x_pos_key < key_s; x_pos_key++)
		{
			for (int y_pos_key = 0; y_pos_key < key_s; y_pos_key++)
			{
				if (0 <= x_pos + x_pos_key && x_pos + x_pos_key < lock_s && 0 <= y_pos + y_pos_key && y_pos + y_pos_key < lock_s)
				{
					if (lock[x_pos + x_pos_key][y_pos + y_pos_key] == key[x_pos_key][y_pos_key])
					{
						return false; //0->0 , 1->1 인 경우 return false
					}

					else if(lock[x_pos + x_pos_key][y_pos + y_pos_key] == 0)
					{
						match_nut++; //0->1 인 경우
					}
				}



			}
		}

		if(match_nut >= lock_nut)
			return true;

		else false;
	}



	bool find_key() //key가 lock에 맞는 지 확인 하는 과정
	{
		for(int x_pos = -key_s + 1; x_pos < lock_s + key_s-1; x_pos++) //이것의 범위는 key와 lock이 한 칸만 겹치게 꽃아넣더라도 자물쇠가 풀리는 지 
		{																//알 아볼 수 있게 구성
			for (int y_pos = -key_s + 1; y_pos < lock_s + key_s - 1; y_pos++)
			{
				if(sub_find_key(x_pos, y_pos) == true) return true;
			}
		}

		return false;
	}



	void turnRight90()//o(n*n) 반시계방향으로 회전시키는 함수이다. 90도 이동
	{
		for (int x_pos = 0; x_pos < key_s; x_pos++)
		{
			for (int y_pos = x_pos; y_pos < key_s; y_pos++)
			{
				int t_1 = key[x_pos][y_pos];
				key[x_pos][y_pos] = key[y_pos][x_pos];
				key[y_pos][x_pos] = t_1; //(x,y)와 (y,x)의 값을 서로 교환함
			}
		}

		
		for (int x_pos = 0; x_pos < key_s/2; x_pos++)
		{
			for (int y_pos = 0; y_pos < key_s; y_pos++)
			{
				int t_1 = key[x_pos][y_pos];
				key[x_pos][y_pos] = key[key_s - x_pos - 1][y_pos];
				key[key_s - x_pos - 1][y_pos] = t_1; //세로 축 중심으로 교환함
			}
		}
		
	}


	void showing_graph(vector<vector<int>> &graph) //key, lock을 확인할 수 있는 함수
	{
		for (int x_pos = 0; x_pos < graph.size(); x_pos++)
		{
			for (int y_pos = 0; y_pos < graph.size(); y_pos++)
			{
				if (graph[x_pos][y_pos] > 0)
					cout << "* ";

				else
					cout << "0 ";
			}

			cout << endl;
		}
	}
};


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	
	solve* sol1 = new solve(key, lock);
	
	bool answer = sol1->answer;
	return answer;
}



vector<vector<int>> key1 = {{0, 0, 0},{1, 0, 0},{0, 1, 1}};
vector<vector<int>> lock1 = {{ 1, 1, 1 },{ 1, 1, 0 },{ 1, 0, 1 }};  //example 1



vector<vector<int>> key2 = { { 1, 1, 1,1 },{ 1, 1, 1,1 },{0,0,1,0}, { 1, 1, 1,1 }};
vector<vector<int>> lock2 = {{ 1, 1, 1,1,1 },{ 1, 1, 1,1,0 },{ 1, 1, 1,1,0 },{ 1, 1, 1,1,1 },{ 1, 1, 1,1,1 } }; //example 2



vector<vector<int>> key3 = { {0,0,0,0,0,0,0,0,0,1},{ 0,0,0,0,0,0,0,0,0,1 } ,{ 0,0,0,0,0,0,0,0,0,1 } ,{ 0,0,0,0,0,1,0,0,0,1 } ,{ 0,0,0,0,0,0,0,0,0,1 } ,{ 0,0,0,0,0,0,0,0,0,1 } ,{ 0,0,0,0,0,0,0,0,0,1 } ,{ 0,0,0,0,0,0,0,0,0,1 } ,{ 0,0,0,0,0,0,0,0,0,1 } ,{ 0,0,0,0,0,0,0,0,0,1 }};
vector<vector<int>> lock3 = { { 1,0,0,0,0,0,0,0,0,1 },{ 0,0,0,0,0,0,0,0,0,1 } ,{ 0,0,0,0,0,0,0,0,0,1 } ,{ 0,0,0,0,0,0,0,0,0,1 } ,{ 0,0,0,0,0,0,0,0,0,1 } ,{ 0,0,0,0,0,0,0,0,0,1 } ,{ 0,0,0,0,0,0,0,0,0,1 } ,{ 0,0,0,0,0,0,0,0,0,1 } ,{ 0,0,0,0,0,0,0,0,0,1 } ,{ 0,0,0,0,0,0,0,0,0,1 }};
//example 3


int main(void)
{
	cout << solution(key1, lock1) << endl;	
	system("pause");//잠시 main아 멈춰라 얍!
}