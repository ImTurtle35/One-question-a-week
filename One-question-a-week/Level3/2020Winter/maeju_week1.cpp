#include <string>
#include <vector>
#include <iostream>

using namespace std;


class solve
{
	public:
		string begin; //시작하는 단어
		string target; //찾고자 하는 단어
		vector<string> words; //단어집 모음
		int answer = 0;


		int how_same(string &begin01, string &target01) //begin과 target의 단어가 얼마나 다른지, 1글자만 달라야 의미가 있다.
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

			return differ; //differ은 반납한다.
		}

		void find(string& begin1, string& target1, int deepth)
		{
			if (begin1 == target1) //target 단어를 찾았을 경우
			{
				if(this->answer == 0) //첫 시도, 0은 변환할 수 없음을 의미하므로 바로 변환한다.
					this->answer = deepth;

				else if(this->answer > deepth) //두 번째 시도 부터는 최솟값만을 거둔다.
					this->answer = deepth;	
			}

			else
			{
				for (int word_n = 0; word_n < words.size(); word_n++)
				{
					if (how_same(begin1, words[word_n]) == 1) //시작 글자랑 다음 글자
					{
						string begin_exe = begin1;
						begin1 = "";
						find(words[word_n], target1, deepth + 1); //dfs로 갈 때, 갔던데는 빼고 탐색하기 위해서
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












