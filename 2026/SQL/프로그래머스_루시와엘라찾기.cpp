--코드를 입력하세요
SELECT ANIMAL_ID, NAME, SEX_UPON_INTAKE
from ANIMAL_INS
where NAME in("Lucy", "Ella", "Pickle", "Rogan", "Sabrina", "Mitty")
order by ANIMAL_ID
//
//#include<iostream>
//#include <string>
//#include <vector>
//#include <unordered_map>
//#include <sstream>
//#include <algorithm>
//#include<set>
//#include<deque>
//typedef long long ll;
//using namespace std;
//typedef struct record{
//    int time;
//    string name;
//    string um;
//};
//string solution(string m, vector<string> musicinfos) {
//    string answer = "";
//    vector<record>records;
//    for (int i = 0;i < m.size();i++) {
//        if (m[i] == '#') {
//            m.erase(i, 1);
//            m[i - 1] += 'a' - 'A';
//            i--;
//        }
//    }
//    for (auto musicinfo : musicinfos) {
//        string st, ls, name, mel;
//        stringstream ss(musicinfo);
//
//        getline(ss, st, ',');
//        getline(ss, ls, ',');
//        getline(ss, name, ',');
//        getline(ss, mel);
//        int time = -stoi(st.substr(0, 2))*60-stoi(st.substr(3,2))+(stoi(ls.substr(0, 2)) * 60 + stoi(ls.substr(3, 2)));
//
//        for (int i = 0;i < mel.size();i++) {
//            if (mel[i] == '#') {
//                mel.erase(i,1);
//                mel[i - 1] += 'a' - 'A';
//                i--;
//            }
//        }
//        string um = "";
//        for (int i = 0;i < time;i++) {
//            char code = mel[i % mel.size()];
//            um +=code;
//        }
//
//        if (um.find(m)!=string::npos) {
//            record r;
//            r.time = time;
//            r.name = name;
//            r.um = um;
//            records.push_back(r);
//        }
//    }
//    if (records.empty()) {
//        return "(None)";
//    }
//    int mxt = 0;
//    for (auto record : records) {
//        if (mxt < record.time) {
//            mxt = record.time;
//            answer = record.name;
//        }
//    }
//   
//    return answer;
//}
//int main() {
//
//
//    solution("ABC", { "12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF" });
//}