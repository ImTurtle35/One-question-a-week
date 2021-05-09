#include <string>
#include <vector>
#include <iostream>
#include <map>
#pragma warning(disable:4996)
using namespace std;


class chat_data
{
public:
    chat_data(string status0, string id0, string name0)
    {
        this->id = id0;
        this->name = name0;
        this->status = status0;
        this->original = id0 + "," + name0 + "," + status0;
    }

    string id;
    string name;
    string status;
    string original;
};


void print(vector<string> data)
{
    for (int x = 0; x < data.size(); x++)
    {
        cout << data[x] << endl;
    }

    cout << endl;
}

vector<string> split_0(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

vector<chat_data>data00; //data collection
vector<string> answer00; //automatic freely?
vector<string> answer01;
map<string, int> data_queue;

string enter1 = "님이 들어왔습니다.";
string leave1 = "님이 나갔습니다.";


int find_index(string& id0) //where index
{
    map<string,int>::iterator index0 = data_queue.find(id0);
    if (index0 == data_queue.end())
        return -1;

    else return  index0->second;
}

vector<string> solution(vector<string> record) {
    try {
        
        for (int x = 0; x < record.size(); x++)
        {
            vector<string> record1 = split_0(record[x] + " "," ");
            if (record1.size() < 2) throw string("record1 size is small than 2 " + to_string(record1.size()));


            if (record1[0][0] == 'L')
            {
                data00[find_index(record1[1])].status = "Leave";
                answer00.push_back(record1[1]);
                answer01.push_back(leave1);
            }

            //if (record1.size() < 3) throw string("no name " + to_string(record1.size()));
            else if (record1[0][0] == 'E')
            {
                int index00 = find_index(record1[1]);

                if (index00 < 0) {
                    data00.push_back(chat_data(record1[0], record1[1], record1[2]));
                    data_queue.insert(make_pair(record1[1], data00.size() - 1));
                }

                else
                {
                    data00[index00].name = record1[2];
                    data00[index00].status = "Enter";
                }

                answer00.push_back(record1[1]);
                answer01.push_back(enter1);
            }

            else if (record1[0][0] == 'C')
            {
                int index00 = find_index(record1[1]);

                data00[index00].status = "Change";
                data00[index00].name = record1[2];
            }

            else throw string(record1[0]);

        }//setting

        vector<string> answer;

        if (answer00.size() != answer01.size()) throw(string("command size is strange"));
      
        for (int x = 0; x < answer00.size(); x++)
        {
            int index00 = find_index(answer00[x]);
            if (index00 < 0) throw(string("in finding error"));
            
            answer.push_back(data00[index00].name + answer01[x]);
        }//finding

        if (answer.size() == 0) throw(string("answer is zero"));

        //print(answer);
        return answer;
    }

    catch (exception e)
    {
        cerr << e.what() << endl;
    }

    catch (string e1)
    {
        cerr << "string " << e1 << "error" << endl;
    }
    
}

vector<string> test1 = { "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" };

int main(void)
{
    solution(test1);
    return 0;
}
