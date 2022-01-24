#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

// 문자열 소문자로 변환
string strtolower(string s) {
    for(int i{0}; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

int solution(string word, vector<string> pages) {
    int answer = 0;

    // pages와 word를 모두 소문자로 통일
    word = strtolower(word);
    for(int i{0}; i < pages.size(); i++) {
        pages[i] = strtolower(pages[i]);
    }

    // 각 웹페이지의 url을 뽑아내어 map에 index와 매칭
    map<string, int>url;
    string metatag = "<meta property=\"og:url\" content=\"https://";
    for(int i{0}; i < pages.size(); i++) {
        int tagstart = pages[i].find(metatag) + metatag.length();
        int tagend = pages[i].substr(tagstart).find("\"/>");
        url.insert({pages[i].substr(tagstart, tagend),i+1});
    }


    vector<double>basicscore;
    vector<double>linkscore;
    vector<double>matchscore;
    vector<vector<string>>outerlinks;
    outerlinks.resize(pages.size());

    // 각 웹페이지의 기본 점수, 외부 링크, 링크 점수 찾기
    for(int i{0}; i < pages.size(); i++) {
        // <body> 태그 분리
        int bodystart = pages[i].find("<body>") + 6;
        int bodyend = pages[i].substr(bodystart).find("</body>");
        string body = pages[i].substr(bodystart, bodyend);
        
        double score = 0;
        string tmp = body;
        // 문자열 아닌 부분 공백 처리
        for(int i{0}; i < tmp.length(); i++) {
            if(tmp[i] < 'a' || tmp[i] > 'z') tmp[i] = ' ';
        }
        // 공백 단위로 끊어서 검색어 찾아 기본 점수 찾기
        stringstream ss(tmp);
        ss.str(tmp);
        string w;
        while(ss >> w) {
            if(w == word) score++;
        }
        basicscore.push_back(score);

        // 외부 링크를 모두 찾아 저장
        string href = "<a href=\"https://";
        tmp = body;
        int linkstart = 0;
        while((linkstart = tmp.find(href)) != -1) {
            linkstart += href.length();
            int linkend = tmp.substr(linkstart).find("\">");
            string link = tmp.substr(linkstart,linkend);
            tmp = tmp.substr(linkstart + linkend + 2);
            outerlinks[i].push_back(link);
        }

        // 웹 페이지의 기본점수 / 외부 링크수를 저장 
        score = 0;
        if(outerlinks[i].size())
            score = (double)basicscore[i]/(double)outerlinks[i].size();
        linkscore.push_back(score);
    }

    
    // 위에서 찾은 값으로 매칭 점수 계산
    double maxscore = 0;
    for(int i{0}; i < basicscore.size(); i++) {
        matchscore.push_back(basicscore[i]);
    }
    for(int i{0}; i < linkscore.size(); i++) {
        for(int j{0}; j < outerlinks[i].size(); j++) {
            int outerindex = url[outerlinks[i][j]] - 1;
            // 외부 링크가 존재하지 않는 경우 제외
            if(outerindex == -1) continue;
            matchscore[outerindex] += linkscore[i];
        }
    }
    // 정답 찾기
    for(int i{0}; i < matchscore.size(); i++) {
        if(matchscore[i] > maxscore){
            maxscore = matchscore[i];
            answer = i;
        }
    }

    return answer;
}
