/*
[로직] 사이클 없는 트리라 리프부터 올라오며 결정: 감시 안 된 자식이 하나라도 있으면 부모가 설치(그 자식을 감시할 곳은 부모뿐)
[문법] dfs가 상태 0/1/2를 int로 반환 → children[dfs(there)]++로 상태별 자식 수 세기, for문 끝난 자리가 후위 처리 지점
[실수] 깊이별로 설치/미설치를 줄무늬처럼 번갈아 정하려 함 → 리프 깊이가 제각각이라 틀림(예제1은 1,2 둘 다 설치). 층 말고 자식 상태로 판단
[엣지] 트리가 여러 개라 모든 방에서 dfs, 루트가 UNWATCHED면 부모가 없으니 직접 설치 → 고립된 방도 1대씩(1000 1 → 999)
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int UNWATCHED = 0;
const int WATCHED   = 1;
const int INSTALLED = 2;

vector<vector<int>> adj;
vector<int> visited;
int installed;

int dfs(int here) {
    visited[here] = 1;
    int children[3] = {0, 0, 0};

    for (int i = 0; i < adj[here].size(); i++) {
        int there = adj[here][i];
        if (visited[there] == 0)
            children[dfs(there)]++;
    }

    if (children[UNWATCHED] > 0) {
        installed++;
        return INSTALLED;
    }
    if (children[INSTALLED] > 0)
        return WATCHED;
    return UNWATCHED;
}

int solve(int G) {
    visited.assign(G, 0);
    installed = 0;

    for (int i = 0; i < G; i++) {
        if (visited[i] == 0 && dfs(i) == UNWATCHED)
            installed++;
    }
    return installed;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int C, H, G, p1, p2;
	cin >> C;

	while (C--) {
		cin >> G >> H;
		adj = vector<vector<int>>(G);

		for (int i = 0; i < H; i++) {
			cin >> p1 >> p2;

			adj[p1].push_back(p2);
			adj[p2].push_back(p1);
		}

		cout << solve(G) << endl;
	}

	return 0;
}