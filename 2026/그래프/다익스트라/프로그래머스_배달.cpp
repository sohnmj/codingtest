
/*
다음에는 문제 잘 읽고 변수들의 경계값 설정을 꼼꼼하게 확인하겠다.
*/
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include<queue>
using namespace std;
int adj[51][51];
int dist[51] = { 0, };
int n;
void da() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,1 });
    while (!pq.empty()) {
        pair<int, int>cur = pq.top();
        pq.pop();
        int node = cur.second;
        int d = cur.first;
        if (dist[node] < d) continue;

        for (int i = 1; i <= n; i++) {
            if (adj[node][i] != 10001 && dist[i] > d + adj[node][i]) {
                dist[i] = d + adj[node][i];
                pq.push({ dist[i], i });
            }
        }
    }

}
int solution(int N, vector<vector<int> > road, int K) {
    n = N;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            adj[i][j] = 10001;
        }
    }
    int answer = 0;

    for (auto r : road) {
        int a = r[0], b = r[1], c = r[2];
        if (adj[a][b] > c) {
            adj[a][b] = c;
            adj[b][a] = c;
        }
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = 500001;
    }
    dist[1] = 0;
    da();
    for (int i = 1; i <= n; i++) {
        if (dist[i] <= K) {
            answer++;
        }
    }

    return answer;
}
int main() {
    std::vector<std::vector<int>> vectors = {
            {1, 2, 1},
            {2, 3, 3},
            {5, 2, 2},
            {1, 4, 2},
            {5, 3, 1},
            {5, 4, 2}
    };

    cout<<solution(2,vectors,0);
    

}