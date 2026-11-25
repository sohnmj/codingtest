/*
[로직] B 아닌 돌을 K개까지 품는 최장 윈도우 찾기, 새 돌이 들어오면 s = 맨 앞 돌 위치 + 1로 이동
[문법] B 아닌 위치를 전부 cur에 push하고 head로 윈도우 시작만 가리킴(당기기 없이 O(N)), 답은 bestHead만 저장했다가 마지막에 생성
[실수] maxb=e-s-+1 오타(-(+1)로 계산됨), cur[0..2]로 K=3 고정, 최댓값이 아닌데도 ans 덮어쓰기
[엣지] B 아닌 돌 < K면 전부 반환, K=0 가드, B 아닌 돌로 끝나는 구간은 직전 구간보다 짧거나 같아서 비교 생략
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> pebbles(int N, int K, string S) {
    vector<int> ans;
    if (K <= 0) return ans;

    vector<int> cur;
    int s = 0, e = 0, maxb = 0;
    int k = K;
    while (e < N && k > 0) {
        if (S[e] != 'B') { k--; cur.push_back(e); }
        maxb++;
        e++;
    }
    if ((int)cur.size() < K) return cur;

    int head = 0;
    int bestHead = 0;
    for (; e < N; e++) {
        if (S[e] == 'B') {
            if (maxb < e - s + 1) {
                maxb = e - s + 1;
                bestHead = head;
            }
        } else {
            s = cur[head] + 1;
            head++;
            cur.push_back(e);
        }
    }

    for (int i = bestHead; i < bestHead + K; i++) ans.push_back(cur[i]);
    return ans;
}

int main() {
    int N, K;
    string S;

    cin >> N >> K >> S;

    vector<int> ans = pebbles(N, K, S);

    cout << ans.size() << '\n';
    for (int x: ans) cout << x + 1 << ' ';
    cout << '\n';

    return 0;
}