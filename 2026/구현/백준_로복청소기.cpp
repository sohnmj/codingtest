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
구현 문제였고 더 빨리 풀도록 노력해야겠다.
이미 청소된 구역과 벽에 대한 표현을 다르게 해야한다.... 왜냐하면 후진할때 청소된 구역을 갈수 있어야하지만 벽은 못간다.
*/
int m,n ;
int dr[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int ct = 0;
void move(int r, int c, int d, vector<vector<int>>&mp) {

    int empty = 0;
    if (mp[r][c] == 0) {
        mp[r][c] = -1;
        ct++;
    }
    int nd = d;
    for (int i = 0; i < 4; i++) {
        nd = (nd - 1 >= 0) ? nd - 1 : 3;
        int nr = r + dr[nd][0];
        int nc = c + dr[nd][1];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
            if (mp[nr][nc] == 0) {
                empty = 1;
                break;
            }
        }
    }
    if (empty == 1) {
        d = nd;
        move(r + dr[d][0], c + dr[d][1], nd, mp);
    }
    else {
        nd = (d - 1 >= 0) ? d - 1 : 3;
        nd = (nd - 1 >= 0) ? nd - 1 : 3;
        int nr = r + dr[nd][0];
        int nc = c + dr[nd][1];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
            if (mp[nr][nc] != 1) {
                move(nr, nc, d, mp);
            }
        }
    }
}
int main() {
    
    int  x, y,direction;
    cin >> n >> m >> x >> y >> direction;
    vector<vector<int>>mp (n, vector<int>(m));
   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
        }
    }
    move(x, y, direction,mp);
    cout << ct;
}