#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	unordered_map<string, bool> chk_map;

	for (int i = 0; i < phone_book.size(); i++) {
		chk_map[phone_book[i]] = true;
	}

	for (int i = 0; i < phone_book.size(); i++) {
		string chk_num = "";
		for (int j = 0; j < phone_book[i].size(); j++) {
			chk_num += phone_book[i][j];
			if (chk_map[chk_num] && chk_num != phone_book[i]) {
				answer = false;
				return answer;
			}
		}
	}
	return answer;
}

int main() {
	vector<string> phone_book = { "119", "97674223", "1195524421" };
	cout << boolalpha << solution(phone_book) << endl;
}