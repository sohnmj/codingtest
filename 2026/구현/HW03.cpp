#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    vector<vector<int>> D(N + 1, vector<int>(N + 1, 0));
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            cin >> A[i][j];
        }
    }
    int q;
    cin >> q;
    for (int i = 0;i < q;i++) {
        int r1, r2, c1, c2, v;
        cin >> r1 >> c1 >> r2 >> c2 >> v;
        r1--;
        c1--;
        D[r1][c1] += v;
        D[r1][c2] -= v;
        D[r2][c1] -= v;
        D[r2][c2] += v;
    }
    for (int i = 0;i < N;i++) {
        for (int j = 1;j < N;j++) {
            D[i][j] += D[i][j - 1];
        }
    }
    for (int i = 1;i < N;i++) {
        for (int j = 0;j < N;j++) {
            D[i][j] += D[i - 1][j];
        }
    }
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            A[i][j] += D[i][j];
        }
    }
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = LLONG_MAX;
struct Edge {
    int u, v, w;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K, S, T;
    cin >> N >> M >> K >> S >> T;
    S--;T--;
    vector<vector<Edge>>colors(K);
    for (int i = 0;i < M;i++) {
        int u, v, w, c;
        cin >> u >> v >> w >> c;
        u--;v--;
        colors[c - 1].push_back({ u,v,w });
    }
    vector<ll>dist(N, INF);
    dist[S] = 0;
    vector<vector<pair<int, int>>>adj(N);
    vector<int> mark(N, -1);
    for (int c = 0;c < K;c++) {
        vector<int>visited;

        for (auto& e : colors[c]) {
            adj[e.u].push_back({ e.v,e.w });
            adj[e.v].push_back({ e.u,e.w });
            if (mark[e.u] != c) { mark[e.u] = c; visited.push_back(e.u); }
            if (mark[e.v] != c) { mark[e.v] = c; visited.push_back(e.v); }
        }
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        for (int x : visited) {
            if (dist[x] < INF) {
                pq.push({ dist[x],x });
            }
        }
        while (!pq.empty()) {
            pair<ll, int>cur = pq.top();pq.pop();
            int u = cur.second;
            ll d = cur.first;
            if (d > dist[u]) {
                continue;
            }
            for (auto vertex : adj[u]) {
                int w = vertex.second;
                int v = vertex.first;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({ dist[v],v });
                }
            }
        }
        for (int x : visited) {
            adj[x].clear();
        }
    }
    if (dist[T] == INF) {
        cout << -1;
        return 0;
    }
    cout << dist[T];
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M;
    cin >> N >> M;
    ll S = 0;
    ll answer = 0;
    while (S < N * M) {
        ll next = S / N;
        ll X = min(M, next + 1);
        S += X;
        answer++;
    }
    cout << answer;
    return 0;
}
