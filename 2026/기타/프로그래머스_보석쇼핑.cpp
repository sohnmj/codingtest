/*
틀린 이유: 새 종류가 나올 때만 창을 갱신해서, 이후 더 짧은 구간을 놓침 제일 먼저 조건에 만족하는 배열이 가장 짧다고 오판함.나중에 나온게 더 짧을 수도 있다.
수정 방향: 매 i마다 push, 앞쪽 중복 제거, 전체 종류 수와 비교, 더 짧을 때만 갱신(슬라이딩 윈도우)
 */
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include<set>
#include<deque>
#include<cmath>
#include<queue>
typedef long long ll;
using namespace std;
set<vector<int>>all;
vector<int>* banned_user ;
vector<int> solution(vector<string> gems) {
    vector<int> answer;

    int mind=gems.size();
    int st;
    int start = 0;
    int len = gems.size();
    unordered_map<string, int>um;
    queue<int>que;
    for (int i = 0;i < gems.size();i++) {
        um[gems[i]]++;
    }
    int sorts = um.size();
    um.clear();
    for (int i = 0;i < gems.size();i++) {
        que.push(i);
        um[gems[i]]++;
        while (um[gems[que.front()]] > 1) {
            um[gems[que.front()]]--;
            que.pop();
            start++;
        }
        if (um.size() == sorts) {
            int d = i - start + 1;
            if (mind > d) {
                mind = d;
                st = start;
            }
        }
    }

    
    answer = { st,st+mind-1 };
    return answer;
}