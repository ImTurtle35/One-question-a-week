#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 2 <= n <= 20000
// 1 <= v <= 50000
// [a,b] -> a�� b���̿� ������ ����
// �ָ� ������ ��� : ������ ������ ���� ���� ���
// ? = 1�� ���� ���� ���� �ָ��� ����� ���� n2


class calcul
{
public:
	int n;
	vector<vector<int>> edge;
	vector<int> check_it;
	int answer = 0;

	void BFS(vector<int> start_index)
	{
		vector<int> start_index_go(0, 0);

		for (int x_pos = 0; x_pos < start_index.size(); x_pos++) {

			check_it[start_index[x_pos]] = 0; //�������� �̹� �˻��� ���̳� �ٸ�����.
		
			for (int y_pos = 0; y_pos < edge[start_index[x_pos]].size(); y_pos++)
			{
				if (check_it[edge[start_index[x_pos]][y_pos]] > 0) //�ٸ��� ������ �ִ� ��� && ���� �˻����� ���� ��
				{
					start_index_go.push_back(edge[start_index[x_pos]][y_pos]);
					check_it[edge[start_index[x_pos]][y_pos]] = 0; //�˻��� ��Ͽ� �־����� �˻��� ������ ġȯ
				}
			}
		}

		if (start_index_go.size() > 0)
		{
			answer = start_index_go.size();
			return BFS(start_index_go);
		}
	}

	calcul(int &n0, vector<vector<int>> &edge0)
	{
		n = n0;
		vector<vector<int>> edge1(n); //making graph
		check_it.assign(n, 1); //�˻��� ������ Ȯ��
		edge = edge1;

		for (int x_pos = 0; x_pos < edge0.size(); x_pos++)//o(n) 
		{//1����� �ε����� 0�� �ִ� ��

			edge[edge0[x_pos][0] - 1].push_back(edge0[x_pos][1] - 1);
			edge[edge0[x_pos][1] - 1].push_back(edge0[x_pos][0] - 1);
			//������ ������ 50000�� ���� �̿��Ͽ� �ð��� �ٿ�����
		}

		
		//print_graph();

		BFS(vector<int>(1, 0)); //���ۿ��� 0��° index�� �Ű澲�� �ȴ�.
		cout << endl << answer << endl;	
		//print_graph();
	}


	void print_graph() //for showing graph
	{
		for (int x_pos = 0; x_pos < edge.size(); x_pos++)
		{
			for (int y_pos = 0; y_pos < edge[x_pos].size(); y_pos++)
			{
				cout << edge[x_pos][y_pos] << " ";
			}

			cout << endl;
		}
	}

};

int solution(int n, vector<vector<int>> edge) {

	calcul* exe1 = new calcul(n, edge);
	int answer = exe1->answer;
	return answer;
}



int n00 = 6;
vector<vector<int>> edge00 = { { 3, 6 },{ 4, 3 },{ 3, 2 },{ 1, 3 },{ 1, 2 },{ 2, 4 },{ 5, 2 } };


int main(void)
{
	calcul* exe1 = new calcul(n00, edge00);
	system("pause");
}




