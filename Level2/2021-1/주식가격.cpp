#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {	
	int prices2 = prices.size();
	vector<int> answer(prices2, 0);

	for (int i = 0; i < prices2; i++)
	{
		for (int j = i + 1; j < prices2; j++)
		{
			answer[i]++;
			if (prices[j] < prices[i])
				break;
		}
	}

	answer[prices2 - 1] = 0;

	return answer;
}
