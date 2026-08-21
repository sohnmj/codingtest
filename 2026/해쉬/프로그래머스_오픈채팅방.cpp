/*
조금 번거롭게 풀다가 풀면서 풀이를 수정하였다. 원래는 유저아이디에 따른 아이디 변경마다 실제 로그에서 바꿀려고 했지만 생각해본니깐 마지막에 정달 배열에 넣을 때 
유저야이디에 따른 아이디로 바꾸면 되었다..*/
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
vector<string> split(const string& str) {
    vector<string> result;
    stringstream ss(str);
    string word;

    while (ss >> word) {
        result.push_back(word);
    }
    return result;
}
vector<string> solution(vector<string> records) {
    vector<string> answer;
    vector<pair<string, string>>result;
    unordered_map<string, string>unique;
    string enterm = "님이 들어왔습니다.";
    string exitm = "님이 나갔습니다.";
    for (string record : records) {
        vector<string>splitrecord = split(record);
        if (splitrecord[0] == "Enter") {
            result.push_back({ splitrecord[1],enterm });
            unique[splitrecord[1]] = splitrecord[2];
        }
        else if (splitrecord[0] == "Leave") {
            result.push_back({ splitrecord[1],exitm });
        }
        else {
            unique[splitrecord[1]] = splitrecord[2];
        }
    }
    for (auto row : result) {
        answer.push_back(unique[row.first] + row.second);
    }
    return answer;
}
int main() {

    vector<vector<string>> relation = {
        {"100", "ryan", "music", "2"},
        {"200", "apeach", "math", "2"},
        {"300", "tube", "computer", "3"},
        {"400", "con", "computer", "4"},
        {"500", "muzi", "music", "3"},
        {"600", "apeach", "music", "2"}
    };
 solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" });
}