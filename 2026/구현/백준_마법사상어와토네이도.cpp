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
구현문제다...
시계 방향 반시계방향 문제 도움 많이 된다.
딱히 어려운점은 없었고 그냥 변수들이 많아지니 실수가 많아지는 것 같다.

*/

int n;
int mp[250][250];
int dr[4][2] = { {0,-1},{1,0},{0,1},{-1,0} };
int spread[5][5]= { {0,0,2,0,0},{0,10,7,1,0},{5,0,0,0,0},{0,10,7,1,0}, { 0,0,2,0,0 } };;
int temp[5][5];
int sum = 0;
void rotate() {
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            temp[4-j][i] = spread[i][j];
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            spread[i][j] = temp[i][j];
        }
    }
}
void blow(int r, int c, int dir) {
    int q=mp[r][c];
    
    int nr, nc;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (spread[i][j] > 0) {
                nr = r + i - 2;
                nc = c + j - 2;
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    mp[nr][nc] += q * spread[i][j] / 100;
                }
                else {
                    sum+= q * spread[i][j] / 100;
                }
                mp[r][c]-= q * spread[i][j] / 100;
            }
        }
    }
    nr = r + dr[dir][0];
    nc = c + dr[dir][1];
    if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
        mp[nr][nc] += mp[r][c];
    }
    else {
        sum += mp[r][c];
    }
    mp[r][c] = 0;
}
int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>mp[i][j];
        }
    }
    int r = n / 2, c = n / 2;
    int move = 1;
    int dir = 0;
    for(int k=0;k<n-1;k++){
        for (int i = 0; i < move; i++) {
            r = r + dr[dir][0];
            c = c + dr[dir][1];
            blow(r, c, dir);

        }
        dir = (dir + 1) % 4;
        rotate();
        //cout << endl;
        //for (int i = 0; i < n; i++) {
        //    for (int j = 0; j < n; j++) {
        //        cout << mp[i][j] << ' ';
        //    }
        //    cout << endl;
        //}
        for (int i = 0; i < move; i++) {
            r = r + dr[dir][0];
            c = c + dr[dir][1];
            blow(r, c, dir);

        }
        dir = (dir + 1) % 4;
        rotate();
        move++;
        //cout << endl;
        //for (int i = 0; i < n; i++) {
        //    for (int j = 0; j < n; j++) {
        //        cout << mp[i][j] << ' ';
        //    }
        //    cout << endl;
        //}
    }
    move--;
    for (int i = 0; i < move; i++) {
        r = r + dr[dir][0];
        c = c + dr[dir][1];
        blow(r, c, dir);

    }
    cout << sum;
}