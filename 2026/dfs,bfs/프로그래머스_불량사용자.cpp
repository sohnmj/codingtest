/*
 * [오답노트] 프로그래머스 64064 - 불량 사용자
 * ------------------------------------------------------------
 * 문제 핵심
 *  - 불량 아이디(banned_id) 하나당 응모자 아이디(user_id) "서로 다른 한 명"이 대응된다.
 *  - 제재 목록은 "집합"이므로 순서가 달라도 같은 유저 구성이면 같은 경우다.
 *  - 제약: user_id, banned_id 모두 최대 8개 -> 완전탐색(DFS)으로 충분하다.
 *
 * 접근
 *  1) 각 banned_id마다 매칭되는 user 후보를 미리 구한다. (길이 같고, '*' 제외 문자 일치)
 *  2) banned_id 순서대로 후보를 하나씩 골라 DFS
 *  3) 다 고르면 "유저 집합"을 저장해서 중복 제거 후 개수를 센다.
 *
 * ------------------------------------------------------------
 * 내가 틀린 부분
 *
 * [오답 1] dfs의 else 분기 (가장 큰 버그)
 *    else { dfs(d + 1, ...); }
 *  - 이미 쓴 유저를 만났을 때 "배정 없이" 다음 depth로 넘어갔다.
 *  - 예: 불량 아이디 2개가 모두 {0, 1}에 매칭될 때
 *        d=0에서 유저 0 선택 -> d=1에서 유저 0은 visited -> 배정 없이 d=2 도달
 *        -> {0} 하나만 담긴 불완전한 조합이 정답에 포함됨
 *  - 원인: 문제 조건을 놓쳤다.
 *      "불량 아이디 하나는 응모자 아이디 중 하나에 해당" -> 불량 아이디마다 대응 유저가 반드시 존재
 *      "같은 응모자 아이디가 중복해서 제재 목록에 들어가지 않음" -> 한 유저가 두 불량 아이디를 담당 불가
 *      => 불량 아이디 개수 == 제재 유저 수, 각자 서로 다른 유저
 *  - 해결: 이미 쓴 유저는 그냥 continue (그 후보는 쓸 수 없을 뿐)
 *
 * [오답 2] 순서 중복 미처리
 *  - cur_ban은 불량 아이디 순서대로 쌓이므로 {0,1}과 {1,0}이 서로 다른 원소로 세졌다.
 *  - 해결 (택1)
 *      a) 기정렬한 복사본을 set<vector<int>>에 넣기
 *      b) cur_ban을 처음부터 set<int>로 두고 set<set<int>>에 넣기
 *      c) visited 배열 자체를 집합으로 보고 set<vector<int>>에 넣기
 *      d) 비트마스크 int 하나를 set<int>에 넣기  <- 가장 가볍고 코테에서 자주 쓰는 패턴
 *
 * [오답 3] 메모리 할당 실수
 *    banned_user = new vector<int>(banned_id.size());   // X : vector 하나를 만든 것
 *    banned_user = new vector<int>[banned_id.size()];   // O : vector 배열
 *  - 앞의 코드는 banned_user[1]부터 범위를 벗어나 정의되지 않은 동작이 된다.
 *

 * ------------------------------------------------------------
 * 기억할 점
 *  - set<int>에서 if (cur_ban.count(x)) continue; 는 "이미 쓴 값이면 건너뛰기"로 올바르다.
 *  - 상태를 값으로 넘기면(mask 전달) 복원(원상복구) 코드가 필요 없다.
 *  - 문제의 "중복 없음/반드시 존재" 같은 제약 문장은 DFS 분기 설계에 직결된다.
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
int answer = 0;
bool match(string ban, string user) {
    int n = ban.length();
    bool result = true;
    for (int i = 0;i < n;i++) {
        if (ban[i] != user[i]) {
            if (ban[i] != '*') {
                return false;
            }
        }
    }
    return result;
}
void dfs(int d, int limit, vector<int>& cur_ban,vector<int>&visited) {
    if (d == limit) {
        if (!all.count(cur_ban)) {
            sort(cur_ban.begin(), cur_ban.end());
            all.insert(cur_ban);
            answer++;
        }
    }
    else {
        for (auto user_idx : banned_user[d]) {
            if (!visited[user_idx]) {
                visited[user_idx] = 1;
                cur_ban.push_back(user_idx);
                dfs(d + 1, limit, cur_ban, visited);
                cur_ban.pop_back();
                visited[user_idx] = 0;
            }
            
        }
    }
}
int solution(vector<string> user_ids, vector<string> banned_id) {

    vector<int>user_list[9];
    for (int i = 0;i < user_ids.size();i++) {
        string user = user_ids[i];
        int user_len = user.size();
        user_list[user_len].push_back(i);
    }
    banned_user = new vector<int>[banned_id.size()];

    for (int i = 0;i < banned_id.size();i++) {
        string ban = banned_id[i];
        int ban_len = ban.size();
        for (int user_idx : user_list[ban_len]) {
            string user_id = user_ids[user_idx];
            if (match(ban, user_id)) {
                banned_user[i].push_back(user_idx);
            }
        }
    }
    vector<int>visited(user_ids.size(), 0);
    vector<int>cur_ban;
    dfs(0, banned_id.size(), cur_ban, visited);

    return answer;
}