/*
[로직] 수 대신 상태 2n개로 BFS(n 미만이면 수 자체, n 이상이면 n+나머지) → 간선 1개=한 자리라 최단 경로=최소 수, 목표는 n+m
[문법] 전이 there=here*10+j, n 이상이면 n+there%n / queue<pair<int,string>>로 상태+만든 수 함께 저장, allow는 sort로 작은 숫자부터
[실수] visited 없이 수를 int로 큐에 넣음 → 0 7 3에서 0→0 무한루프·오버플로, 복원 while(ans%10)은 0에서 멈춤, cur>n이 아니라 >=n
[엣지] 숫자가 0뿐이면 출발점을 못 벗어나 큐가 비고 IMPOSSIBLE, 흰 0(출발 0번)과 회색 0(n번)은 다른 상태
*/
#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string Gifts(const string& d, int n, int m) {
    vector<int> allow;
    for (int i = 0; i < d.size(); i++)
        allow.push_back(d[i] - '0');
    sort(allow.begin(), allow.end());

    vector<bool> visited(2 * n, false);
    queue<pair<int, string>> que;
    visited[0] = true;
    que.push({0, ""});

    while (!que.empty()) {
        int here = que.front().first;
        string num = que.front().second;
        que.pop();

        if (here == n + m) return num;

        for (auto j : allow) {
            int there = here * 10 + j;
            if (there >= n) there = n + there % n;
            if (visited[there]) continue;
            visited[there] = true;
            que.push({there, num + char('0' + j)});
        }
    }
    return "IMPOSSIBLE";
}

int main() {
    ios_base::sync_with_stdio(0);
    int test_num;
    cin >> test_num;

    while (test_num--) {
        string d;
        int n, m;
        cin >> d >> n >> m;

        cout << Gifts(d, n, m) << "\n";
    }

    return 0;
}