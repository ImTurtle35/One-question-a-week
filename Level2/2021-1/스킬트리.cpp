#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	
	for (int j = 0; j < skill_trees.size(); j++)
	{
		int index = -1;
		int num = 0;

		for (int i = 0; i < skill.length() ; i++)
		{
			int check1 = 0;

			for (int k = 0; k < skill_trees[j].length(); k++)
			{
				if (skill[i] == skill_trees[j][k])
				{
					if (num < 0)
						goto loop1;

					if (index < k)
					{
						index = k; 
						check1++;
					}

					else
						goto loop1;
				} 

			}

			if (check1 < 1) 
				num = -1;

		}
	
		answer++;
	loop1:; 

	}

	return answer;
}




