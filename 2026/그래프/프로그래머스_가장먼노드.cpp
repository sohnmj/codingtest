#include<iostream>
#include <string>
#include <vector>
#include<map>
#include<queue>
#include<stack>
#include<utility>
#include<algorithm>
#include<cmath>
#include<set>
#include <unordered_map>
using namespace std;
int solution(int n, vector<vector<int>> edge) {
    priority_queue<pair<int, int>> pq;
    int answer = 1;
    int**adj = new int*[n+1];
    int *vis = new int[n + 1];
    int* dis = new int[n + 1];
    for (int i = 1; i <= n; i++) {
        adj[i] = new int[n + 1];
        vis[i] = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) adj[i][j] = 0;
            else adj[i][j] = -1;
        }
    }
    for (auto i : edge) {
        int x = i[0];
        int y = i[1];
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    pq.push({ 0,1 });

    int max = -1;
    
    while(!pq.empty()) {
        pair<int, int>top;
        top = pq.top();
        pq.pop();
        int node = top.second;
        if (vis[node]) {
            continue;
        }
        vis[node] = 1;
        int d = top.first * -1;
        if (max == d) {
            answer++;
        }
        else if (max < d) {
            max = d;
            answer = 1;
        }
        for (int i = 1; i < n + 1; i++) {
            if (adj[node][i] == 1&&vis[i]==0) {
                pq.push({-( 1 + d),i });
            }
        }
    }
    return answer;
}
int main() {
    vector<vector<int>> v = {
       {3, 6},
       {4, 3},
       {3, 2},
       {1, 3},
       {1, 2},
       {2, 4},
       {5, 2}
    };   string str = "4177252841";
    int s = solution(6,v);
    cout << s;
}