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


/*
구현 문제에서 사소한 실수가 큰 시간을 잡아먹게하는 듯 싶다.for (int i = 0; i < directions[cctvs[d][0]].size(); i++) diretctions안에 단순히 d를 넣어서 고생했다.
*/

vector<vector<int>> cctvs;

int dr[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

vector<vector<vector<int>>> directions = {
    {{0},{1},{2},{3}},
    {{0,2},{1,3}},
    {{0,1},{1,2},{2,3},{3,0}},
    {{0,1,2},{1,2,3},{2,3,0},{3,0,1}},
    {{0,1,2,3}}
};
int mn = 1e9;
int n, m;
vector<pair<int, int>>lc;

void fill(vector<vector<int>>& mp,int d) {
    int x = lc[d].second;
    int y = lc[d].first;
    for (auto direct : directions[cctvs[d][0]][cctvs[d][1]]) {
        int nx = x;
        int ny = y;
        while (1) {
            nx += dr[direct][1];
            ny += dr[direct][0];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                break;
            }
            if (mp[ny][nx] == 6) {
                break;
            }
            if (mp[ny][nx] == 0) {
                mp[ny][nx] = 7;
            }
        }
    }
}
int countC(vector<vector<int>>mp) {
    for (int i = 0; i < cctvs.size();i++) {
        fill(mp, i);
    }
    int c = 0;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            if (mp[i][j] == 0) c++;
    return c;
}
void dfs(int d,int len,vector<vector<int>>mp) {
    if (d == len) {
        int c = countC(mp);
        if (mn > c) {
            mn = c;
        }
    }
    else {
        for (int i = 0; i < directions[cctvs[d][0]].size(); i++) {
            cctvs[d][1] = i;
            dfs(d + 1, len, mp);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<int>> mp(8,vector<int>(8));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {       
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];  
            int num = mp[i][j];
            if (num > 0 && num < 6) {
                lc.push_back({ i,j });
                cctvs.push_back({num-1,0});
            }
        }
    }
    int len = lc.size();
    dfs(0, len,mp);
    cout << mn;
}