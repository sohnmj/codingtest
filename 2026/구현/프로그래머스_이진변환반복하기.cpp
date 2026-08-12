/*
if문 짤때 신중하게 그리고 문제 꼼꼼하게 읽자*/
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

void toBinary(int num, pair<int, int>& cnt) {
    while (num) {
        if (num % 2 == 1) {
            cnt.first++;
        }
        else {
            cnt.second++;
        }
        num /= 2;
    }
}
vector<int> solution(string s) {
    vector<int> answer(2, 0);
    int zcnt = 0;
    int num;
    for (auto i : s) {
        if (i == '0') {
            zcnt++;
        }
    }

    if (zcnt == 0 && s.length() == 1) {
        return answer;
    }
    num = s.size() - zcnt;
    answer[0]++;
    answer[1] += zcnt;
    while (1) {
        zcnt = 0;
        pair<int, int>cnt = { 0,0 };
        toBinary(num, cnt);
        zcnt = cnt.second;
        num = cnt.first;
        if (!zcnt && num == 1) break;
        answer[0]++;
        answer[1] += zcnt;
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
    vector<int>ans=solution(grid);
    for( auto i : ans) {
        cout << i <<" ";
    }
}