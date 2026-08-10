/*
 [문제 원인 및 개선 포인트 회고]

 1. 입력 데이터 정렬 문제:
    - 손님의 주문 목록(orders)이 알파벳순으로 정렬되어 있지 않음.
    - 기존: DFS 조합을 생성할 때마다 sort()를 수행하여 불필요한 연산 낭비 발생.
    - 개선: 탐색 시작 전 orders의 각 문자열을 미리 1회만 정렬해 두면 DFS 내 sort() 제거 가능.

 2. 코스 크기별 분리 탐색:
    - 기존: 모든 course 크기에 대한 조합을 한 번에 구하고 전체 um(unordered_map)을 순회하여 탐색량이 많음.
    - 개선: course 크기(len)별로 루프를 돌며 조합을 구하고, 각 크기가 끝날 때마다 um을 초기화(clear).
            -> 탐색 및 메모리 공간을 대폭 줄일 수 있음.
*/
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

unordered_map<string, int>um;
vector<int>maxcnt;
vector<int>course1;
void dfs(int d,int cur, int limit,string menuset, string menus) {
    if (d == course1[limit]) {
        sort(menuset.begin(), menuset.end());
        um[menuset]++;
        if (um[menuset] > maxcnt[limit]) {
            maxcnt[limit] = um[menuset];
        }
    }
    else {
        int len = menus.length();
        for (int i = cur;i < len;i++) {
            menuset.push_back(menus[i]);
            dfs(d + 1,i+1, limit, menuset, menus);
            menuset.pop_back();
        }
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    course1 = course;
    int n = course.size();
    for (int i = 0;i < n;i++) {
        maxcnt.push_back(0);
    }
    for (auto menus : orders) {
        for (int i=0;i < n;i++) {
            string menu = "";
            dfs(0, 0,i, menu, menus);
        }
    }
    for (int i = 0;i < n;i++) {
        for (auto& cur : um) {
            if (cur.second >= 2) {
                if (cur.first.length() == course[i] && cur.second == maxcnt[i]) {
                    answer.push_back(cur.first);
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
int main() {
    vector<int> vec = { 2,3,4 };

    std::vector<std::string> rawData = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<string>ans=solution(rawData,vec);
    for( auto i : ans) {
        cout << i <<" ";
    }
}