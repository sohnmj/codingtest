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
#include <iomanip> 
using namespace std;


/*
조금 어렵다고 생각되었던 구현 문제였다. 문제를 더 자세히 읽었으면 조금 더 빨리 풀수 있었을 것 같다.
디버깅과정에서 전체적인 테스트보단 단위 테스트가 중요할 것 같다.
*/
int n, k,t;
int mp[12][12];
int mals[12][12][10];
int lay[12][12] = { 0, };
int dt[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
vector<vector<int>>mal;

void move(int num) {
    int x = mal[num][0];
    int y = mal[num][1];
    int dr = mal[num][2];
    int c= mal[num][3];
    int nx = x + dt[dr][0];
    int ny = y + dt[dr][1];
    if ((nx < 0 || nx >= n || ny < 0 || ny >= n) || mp[nx][ny] == 2) {
        if (dr == 0 || dr == 1)dr = 1 - dr;
        else dr = 3 - dr + 2;
        mal[num][2] = dr;
        nx = x + dt[dr][0];
        ny = y + dt[dr][1];
        if ((nx < 0 || nx >= n || ny < 0 || ny >= n) || mp[nx][ny] == 2){}
        else {
            move(num);
        }
    }
    else if (mp[nx][ny] == 0) {
        for (int i = c; i < lay[x][y]; i++) {
            int tnum = mals[x][y][i];
            mal[tnum][0] = nx;
            mal[tnum][1] = ny;
            mal[tnum][3] = lay[nx][ny];
            mals[nx][ny][lay[nx][ny]++] = tnum;
            if (lay[nx][ny] >= 4) {
                cout << t;
                exit(0);
            }
        }
        lay[x][y] = c;
    }
    else {
        for (int i = lay[x][y] - 1; i  >=c; i--) {
            int tnum = mals[x][y][i];
            mal[tnum][0] = nx;
            mal[tnum][1] = ny;
            mal[tnum][3] = lay[nx][ny];
            mals[nx][ny][lay[nx][ny]++] = tnum;
            if (lay[nx][ny] >= 4) {
                cout << t;
                exit(0);
            }
        }
        lay[x][y] = c;
    }

}

int main() {
    
    cin >> n>>k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mp[i][j];
        }
    }
    
    for (int i = 0; i < k; i++) {
        int x, y, dr;
        cin >> x >> y >> dr;
        mal.push_back({x-1,y-1,dr-1,0 });
        mals[x-1][y-1][lay[x-1][y-1]++] = i;
    }
    t = 0;
    while (t < 1001) {
        t++;
        for (int i = 0; i < k; i++) {
            move(i);
        }

    }
    cout << -1;
    
    
}