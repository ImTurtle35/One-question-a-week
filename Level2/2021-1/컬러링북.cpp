#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

void print(vector<vector<int>> &picture)
{
    for (int x = 0; x < picture.size(); x++) {
        for (int y = 0; y < picture[x].size(); y++) {
            cout << picture[x][y] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

void dfs_a(int& n1, int& m1, vector<vector<int>>& picture, map<int, int>::iterator& it)
{
    int data_a = picture[n1][m1]; int m0,m2,n0,n2;
    picture[n1][m1] = 0;
    

    if (n1 - 1 < 0) n0 = 0; else n0 = n1 - 1;
    if (n1 + 1 >= picture.size()) n2 = picture.size() - 1; else n2 = n1 + 1;

    if (m1 - 1 < 0) m0 = 0; else m0 = m1 - 1;
    if (m1 + 1 >= picture[n1].size()) m2 = picture[n1].size() - 1; else m2 = m1 + 1;

    if (picture[n1][m0] == data_a) { it->second += 1; dfs_a(n1, m0, picture, it); }
    if (picture[n1][m2] == data_a) { it->second += 1; dfs_a(n1, m2, picture, it); }
    if (picture[n0][m1] == data_a) { it->second += 1; dfs_a(n0, m1, picture, it); }
    if (picture[n2][m1] == data_a) { it->second += 1; dfs_a(n2, m1, picture, it); }
     
    return;
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0; int max_size_of_one_area = 0;
    
    for(int x = 0 ; x < picture.size() ; x++){
        
        
        for (int y = 0; y < picture[x].size(); y++)
        {
            map<int, int> image_data;
            

            if (picture[x][y] > 0) {
                //print(picture);
                map<int, int>::iterator it;
                                 
                 number_of_area += 1;
                 image_data.insert(pair<int, int>(picture[x][y], 1));
                 it = --image_data.end();
                 dfs_a(x, y, picture, it);
               
                if (it->second >= max_size_of_one_area)max_size_of_one_area = it->second;           
            }
        }
     }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    cout << answer[0] << " " << answer[1] << endl;
    return answer;
}

int m_a = 6; int n_a = 4; vector<vector<int>> picture_a = { {1, 1, 1, 0},{1, 1, 1, 0},{0, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 1}};

int main()
{
    solution(m_a, n_a, picture_a);
    return 0;
}










