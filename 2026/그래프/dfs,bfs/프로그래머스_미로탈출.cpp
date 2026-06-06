/*¤Ð¤©¤¤.*/
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include<cmath>

using namespace std;
int dt[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int bfs(int sx, int sy, int dx, int dy, vector<string> &maps) {
    deque<vector<int>>dq;
    dq.push_back({ sx,sy,0 });
    
    int n = maps.size();
    int m = maps[0].length();
    vector<vector<int>>visited(n, vector<int>(m,0));
    visited[sx][sy] = 1;
    while (!dq.empty()) {
        vector<int>cur = dq.front();
        dq.pop_front();
        int cx = cur[0];
        int cy = cur[1];
        int time = cur[2];
        if (cx == dx && cy == dy) {
            return time;
        }
        for (int i = 0;i < 4;i++) {
            int nx = cx + dt[i][0], ny = cy + dt[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (maps[nx][ny]!='X'&&!visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    dq.push_back({ nx,ny,time + 1 });
                }
            }
        }
    }
    return -1;
}
int solution(vector<string> maps) {
    int answer = 0;
    int sx, sy, lx, ly, dx, dy;
    for (int i = 0;i < maps.size();i++) {
        for (int j = 0;j < maps[0].length();j++) {
            if (maps[i][j] == 'S') {
                sx = i, sy = j;
            }
            if (maps[i][j] == 'L') {
                lx = i, ly = j;
            }
            if (maps[i][j] == 'E') {
                dx = i, dy = j;
            }
        }
    }
    int stol = bfs(sx, sy, lx, ly, maps);
    if (stol == -1) {
        return -1;
    }
    int ltod = bfs(lx, ly,dx,dy, maps);
    if (ltod == -1) {
        return -1;
    }
    return stol+ltod;
}
int main() {
    vector<string> plans = {
       "SOOOL","XXXXO","OOOOO","OXXXX","OOOOE"
    };

    vector<vector<int>> b = {
        {1, 2, 1, 2},
        {2, 1, 2, 1}
    };

    cout<<solution( plans);
    cout << "¾È¿µÇÏ";
}