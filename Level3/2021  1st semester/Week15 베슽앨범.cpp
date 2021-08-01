#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<string,int> p1, pair<string,int>p2) {
    return p1.second > p2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int>genrecount;
    vector<pair<string,int>>genresort;
    for(int i{0}; i < genres.size(); i++) {
        genrecount[genres[i]] += plays[i];
    }
    auto it = genrecount.begin();
    while(it != genrecount.end()) {
        genresort.push_back(make_pair(it->first,it->second));
        it++;
    }
    sort(genresort.begin(),genresort.end(),cmp);
    for(int i{0}; i < genresort.size(); i++) {
        int firstmusic = -1,secondmusic = -1,firstplay = -1,secondplay = -1;
        for(int j{0}; j < genres.size(); j++) {
            if(genres[j] == genresort[i].first) {
                if(plays[j] > firstplay) {
                    secondmusic = firstmusic;
                    secondplay = firstplay;
                    firstmusic = j;
                    firstplay = plays[j];
                }
                else if(plays[j] > secondplay || (plays[j] == firstplay && plays[j] != secondplay)) {
                    secondmusic = j;
                    secondplay = plays[j];
                }
            }
        }
        answer.push_back(firstmusic);
        if(secondplay != -1)answer.push_back(secondmusic);
    }

    return answer;
}
