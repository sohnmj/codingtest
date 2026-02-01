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
*/
int arr[6] = { 0, };
int dr[5] = { 1,2,3,4,5 };
int cur = 0;
int dxy[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
void move(vector<vector<int>>&mp,int dir) {
    int ndr[5];
    if (dir == 1) {   
        ndr[1] = cur;ndr[0] = dr[4];ndr[2] = dr[2];
        ndr[3] = dr[3];ndr[4] = dr[1];cur = dr[0]; 
    }
    else if (dir == 2) {
        ndr[0] = cur; ndr[1] = dr[4]; ndr[2] = dr[2];
        ndr[3] = dr[3]; ndr[4] = dr[0]; cur = dr[1];
    }
    else if (dir == 3) {
        ndr[3] = cur; ndr[2] = dr[4]; ndr[0] = dr[0];
        ndr[1] = dr[1]; ndr[4] = dr[3]; cur = dr[2];
    }
    else {
        ndr[2] = cur; ndr[3] = dr[4]; ndr[0] = dr[0];
        ndr[1] = dr[1]; ndr[4] = dr[2]; cur = dr[3];
    }
    for (int i = 0; i < 5; i++) {
        dr[i] = ndr[i];
    }

}
int main() {
    
    int n, m, x, y,cmd;
    cin >> n >> m >> x >> y >> cmd;
    vector<vector<int>> mp(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
        }
    }
    for (int t = 0; t < cmd; t++) {
        int dir;
        cin >> dir;
        int nx = x + dxy[dir - 1][0];
        int ny = y + dxy[dir - 1][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            move(mp, dir);
            x = nx;
            y = ny;
            if (mp[x][y] == 0) {
                mp[x][y] = arr[cur];
            }
            else {
                arr[cur] = mp[x][y];
                mp[x][y] = 0;
            }
            cout << arr[dr[4]] << "\n";
        }
        

    }


}