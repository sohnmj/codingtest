/*
사소한 실수를 보았을 때는 대충 떼우는 식으로 하지말자
find()함수가 못찾으면 0을 반환하는게 아니라 string::npos를 반환하므로 주의하자 
substr(위치,개수), erase(위치 ,개수)이니깐 주의하면서 사용하자

*/
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include<set>
#include<deque>
typedef long long ll;
using namespace std;
typedef struct record{
    int time;
    string name;
    string um;
};
string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector<record>records;
    for (int i = 0;i < m.size();i++) {
        if (m[i] == '#') {
            m.erase(i, 1);
            m[i - 1] += 'a' - 'A';
            i--;
        }
    }
    for (auto musicinfo : musicinfos) {
        string st, ls, name, mel;
        stringstream ss(musicinfo);

        getline(ss, st, ',');
        getline(ss, ls, ',');
        getline(ss, name, ',');
        getline(ss, mel);
        int time = -stoi(st.substr(0, 2))*60-stoi(st.substr(3,2))+(stoi(ls.substr(0, 2)) * 60 + stoi(ls.substr(3, 2)));

        for (int i = 0;i < mel.size();i++) {
            if (mel[i] == '#') {
                mel.erase(i,1);
                mel[i - 1] += 'a' - 'A';
                i--;
            }
        }
        string um = "";
        for (int i = 0;i < time;i++) {
            char code = mel[i % mel.size()];
            um +=code;
        }

        if (um.find(m)!=string::npos) {
            record r;
            r.time = time;
            r.name = name;
            r.um = um;
            records.push_back(r);
        }
    }
    if (records.empty()) {
        return "(None)";
    }
    int mxt = 0;
    for (auto record : records) {
        if (mxt < record.time) {
            mxt = record.time;
            answer = record.name;
        }
    }
   
    return answer;
}
int main() {


    solution("ABC", { "12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF" });
}