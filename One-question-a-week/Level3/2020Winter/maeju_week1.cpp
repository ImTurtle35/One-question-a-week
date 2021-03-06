#include <string>
#include <vector>
#include <iostream>

using namespace std;


class solve
{
	public:
		string begin; //�����ϴ� �ܾ�
		string target; //ã���� �ϴ� �ܾ�
		vector<string> words; //�ܾ��� ����
		int answer = 0;


		int how_same(string &begin01, string &target01) //begin�� target�� �ܾ �󸶳� �ٸ���, 1���ڸ� �޶�� �ǹ̰� �ִ�.
		{
			int differ = 0;

			if(begin01 != "" && target01 != "")
			for (int string_n = 0; string_n < begin01.length(); string_n++)
			{
				if (begin01[string_n] != target01[string_n])
				{
					differ++;
				}
			}

			return differ; //differ�� �ݳ��Ѵ�.
		}

		void find(string& begin1, string& target1, int deepth)
		{
			if (begin1 == target1) //target �ܾ ã���� ���
			{
				if(this->answer == 0) //ù �õ�, 0�� ��ȯ�� �� ������ �ǹ��ϹǷ� �ٷ� ��ȯ�Ѵ�.
					this->answer = deepth;

				else if(this->answer > deepth) //�� ��° �õ� ���ʹ� �ּڰ����� �ŵд�.
					this->answer = deepth;	
			}

			else
			{
				for (int word_n = 0; word_n < words.size(); word_n++)
				{
					if (how_same(begin1, words[word_n]) == 1) //���� ���ڶ� ���� ����
					{
						string begin_exe = begin1;
						begin1 = "";
						find(words[word_n], target1, deepth + 1); //dfs�� �� ��, �������� ���� Ž���ϱ� ���ؼ�
						begin1 = begin_exe;
					}
				}
			}
		}

		
		solve(string& begin0, string& target0, vector<string>& words0)
		{
			begin = begin0;
			target = target0;
			words = words0;

			find(begin, target,0);
		}
};

int solution(string begin, string target, vector<string> words) {

	solve* sol1 = new solve(begin, target, words);


	int answer = sol1->answer;
	cout << answer << endl;
	return answer;
}


string begin11 = "hit";
string target11 = "cog";
vector<string> words1 = { "hot", "dot", "dog", "lot", "log", "cog" };
vector<string> words2 = { "hot", "dot", "dog", "lot", "log"};


int main(void)
{
	solution(begin11, target11, words1);
	cout << endl;
	solution(begin11, target11, words2);

	system("pause");
}












