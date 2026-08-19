/*
번거롭게 너무 큰 자료구조를 쓴거 같다. 다른 풀이를 보니 find함수를 이용해서 위치를 바로 찾아버리니깐 unordered_map처럼 무거운 자료구조를 사용하지 않아도 되었다
find함수가 실패하면 string:npos를 반환한다.*/
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
bool containChar(string skill, char ch) {
    bool isIn = false;
    for (auto c : skill) {
        if (c == ch) {
            isIn = true;
            break;
        }
    }
    return isIn;
}
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    unordered_map<char, int>um;
    int idx = 0;

    //선행스킬 셋에서 스킬의 위치를 저장하는 자료구조
    for (auto c : skill) {
        um[c] = idx++;
    }

    
    for (auto tree : skill_trees) {
        bool rightSkillTree = true;
        int curidx = 0;
        for (auto ch : tree) {
            if (containChar(skill, ch)) {
                if (curidx == um[ch]) {
                    curidx ++];
                }
                else {
                    rightSkillTree = false;
                    break;
                }
            }
        }
        if (rightSkillTree) {
            answer++;
        }
    }
    return answer;
}
int main() {
    vector<int> vec = { 2,3,4 };

    std::vector<std::string> rawData = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<vector<int>> grid = {
    {1, 1, 0, 0},
    {1, 0, 0, 0},
    {1, 0, 0, 1},
    {1, 1, 1, 1}
    };
    solution("ULURRDLLU");
  
}