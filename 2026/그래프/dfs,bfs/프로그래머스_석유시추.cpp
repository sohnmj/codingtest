
/*
실수 주의 상태값 변화 주의하자 visited
*/
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include<queue>
#include<set>
using namespace std;
int n, m;
int visited[500][500];
int dt[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
unordered_map<int, int>mapp;
void bfs(vector<vector<int>>& land, int sx, int sy) {
    int sym = sx * m + sy + 1;
    int cnt = 1;
    visited[sx][sy] = sym;
    deque<pair<int, int>>dq;
    dq.push_back({ sx,sy });
    while (!dq.empty()) {
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();
        for (int i = 0;i < 4;i++) {
            int cx = x + dt[i][0];
            int cy = y + dt[i][1];

            if (cx >= 0 && cx < n && cy >= 0 && cy < m) {
                if (visited[cx][cy] == 0 && land[cx][cy]) {
                    cnt++;
                    visited[cx][cy] = sym;
                    dq.push_back({ cx,cy });
                }
            }
        }

    }
    mapp[sym] = cnt;
}
int solution(vector<vector<int>> land) {
    int answer = 0;
    n = land.size();
    m = land[0].size();
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (land[i][j] == 1 && visited[i][j] == 0) {
                bfs(land, i, j);
            }
        }
    }
    for (int i = 0;i < m;i++) {
        int am = 0;
        set<int>v1;
        for (int j = 0;j < n;j++) {
            if (visited[j][i] != 0) {
                if (visited[j][i] > 0 && !v1.count(visited[j][i])) {
                    am += mapp[visited[j][i]];
                    v1.insert(visited[j][i]);
                }
            }
        }

        if (answer < am) {
            answer = am;
        }
    }
    return answer;
}
int main() {
    vector<vector<int>> a = {
    {1, 1},
    {1, 3}
    };

    vector<vector<int>> b = {
        {1, 2, 1, 2},
        {2, 1, 2, 1}
    };

    cout<<solution(a,b);
    

}