/*
틀린 이유: 부대원(source)마다 다익스트라/BFS를 돌리려 함 → 최대 500번 × (V+E) 반복이라 시간 초과 위험.
수정 방향:
 1. 간선 가중치가 모두 1이면 다익스트라 대신 BFS로 충분 (먼저 방문한 순서 = 최단거리).
 2. 양방향 그래프라 source→dest 거리 = dest→source 거리.
    → destination에서 BFS 한 번만 돌려 dist[] 채우고, 답은 dist[source] (미방문 -1 = 도달 불가).

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
void bfs(int cur, vector<int>& dist, vector<vector<int>>& adj) {
    queue<pair<int, int>>que;
    que.push({ cur,0 });
    while (!que.empty()) {
        pair<int,int>fron=que.front();
        que,pop();
        int u = fron.first;
        int d = fron.second;
        for (auto v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = d + 1;
                que.push({ v,d + 1 });
            }
        }
    }
}
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>>adj(n);
    for (auto road : roads) {
        int u = road[0]-1;
        int v = road[1]-1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>dist(n, -1);
    dist[destination-1] = 0;
    bfs(destination-1, dist,adj);
    for (auto num : sources) {
        answer.push_back(dist[num - 1]);
    }
    return answer;
}