#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
int ma = 0;
int map[8][8];
vector<pair<int, int>>possible;
int n, m;
void dfs(int map1[][8],int x,int y) {
    int dpx[4] = { 1,0,-1,0 };
    int dpy[4] = { 0,1,0,-1 };
    for (int i=0; i < 4; i++) {
        int nx = x + dpx[i];
        int ny = y + dpy[i];
        if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
            if (map1[ny][nx] == 0) {
                map1[ny][nx] = 2;
                dfs(map1, nx, ny);
            }
        }
    }
}
void solution() {
    int count = 0;
    int map1[8][8];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            map1[i][j] = map[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map1[i][j] == 2) {
                dfs(map1,j,i);

            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map1[i][j] == 0) {
                count++;
            }
        }
    }
    
    if (ma < count) {
        ma = count;
    }
 
}
void comb(int d,int st) {
    if (d == 3) {
        solution();
        return;
    }
    for (int i = st; i < possible.size(); i++) {
        int a = possible[i].first;
        int b = possible[i].second;
        if (map[a][b] == 0) {
            map[a][b] = 1;
            comb(d + 1, i+1);
            map[a][b] = 0;
        }
    }
}
int main() {

    
  
   

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) {
                possible.push_back(make_pair(i, j));
            }
           
        }
    }
    comb(0,0);
    cout << ma;



}