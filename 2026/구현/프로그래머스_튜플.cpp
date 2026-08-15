/*
너무 문자열을 슬라이싱해서 집합하나당 벡터들로 각각 나누어 변환시켜 나중에 개수로 정렬한뒤 하나씩 튜플을 완성시키려했지만
답지를 보니 그냥 빈도수가 많을 수록 앞에 숫자로 나올 수 밖에 없었다. 나도 이런 번뜻임이 있었으면 좋겠다. 다음에 다시 풀어보자
*/
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include<set>
typedef long long ll;
using namespace std;
bool compare(vector<int>& a, vector<int>& b) {
    return a.size() < b.size();
}
vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>>sets;
    set<int>visited;
    for (int i = 1;i < s.length() - 1;i++) {
        if (s[i] == '{') {

            vector<int>arr;
            while (i < s.length() && s[i] != '}') {
                i++;
                string sub = "";
                while (i < s.length() && s[i] != ',' && s[i] != '}') {
                    sub += s[i++];
                }
                arr.push_back(stoi(sub));
            }
            sets.push_back(arr);
        }
    }
    sort(sets.begin(), sets.end(), compare);
    for (auto set1 : sets) {
        for (int i : set1) {
            if (visited.count(i) == 0) {
                visited.insert(i);
                answer.push_back(i);
                break;
            }
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
    solution("100-200*300-500+20");
  
}