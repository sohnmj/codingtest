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
주기성을 가지는 문제이므로, 먼저 주기를 이용해 이동 횟수를 줄였다.

이후에는 복잡한 수학적 처리 없이 단순 반복문으로 시뮬레이션을 구현했다.

일반적인 코딩 테스트에서는 이 정도 최적화만으로도 충분하다고 판단했다.

불필요하게 복잡한 방법을 고민하기보다는, 구현의 안정성과 정확성에 집중하는 것이 더 중요하다고 느꼈다.
*/
int n,m,p;
int mp[100][100];
int sum = 0;
int dx[2] = { -1,1 };
int dy[2] = { 1,-1 };
vector<vector<int>> shark(10001,vector<int>(5));
void move(int ns) {
    int dr = shark[ns][3];
    int s = shark[ns][2];
    int x = shark[ns][0];
    int y = shark[ns][1];
    mp[x][y] -= ns;
    
    if (dr == 1||dr==2) {
        s = s % ((n - 1) * 2);
        int nx = x;
        for (int i = 0; i < s; i++) {
            if (nx == 0) {
                if (dr == 1) {
                    shark[ns][3] = 2;
                    dr = 2;
                }
            }
            else if (nx == n - 1) {
                if (dr==2){
                    shark[ns][3] = 1;
                    dr = 1;
                }
            }
            nx += dx[dr - 1];
        }      
        shark[ns][0] = nx;
        shark[ns][1] = y;
    }
    else {
        s = s % ((m - 1) * 2);
        int ny = y;
        for (int i = 0; i < s; i++) {
            if (ny == 0) {
                if (dr == 4) {
                    shark[ns][3] = 3;
                    dr = 3;
                }
            }
            else if(ny == m - 1) {
                if(dr==3) {
                    shark[ns][3] = 4;
                    dr = 4;
                }
            }
            ny += dy[dr - 3];
        }
        shark[ns][0] = x;
        shark[ns][1] = ny;
    }
}

void moveall() {
    for (int i = 1; i <= p; i++) {
        if (shark[i][4] > 0) {
            move(i);
        }
    }
    for (int i = 1; i <= p; i++) {
        if (shark[i][4] > 0) {
            int x = shark[i][0], y = shark[i][1];
            if (mp[x][y] == 0) {
                mp[x][y] = i;
            }
            else if (mp[x][y] > 0&&shark[i][4]>shark[mp[x][y]][4]) {
                shark[mp[x][y]][4] = 0;
                mp[x][y] = i;
            }
            else {
                shark[i][4] = 0;
            }
        }
    }
}
void caught (int col) {
    for (int i = 0; i < n; i++) {
        if (mp[i][col] > 0) {
            int ns = mp[i][col];
            sum += shark[ns][4];
            shark[ns][4] = 0;
            mp[i][col] = 0;
            break;
        }
    }
}
int main() {

    cin >> n>>m>>p;

    for (int i = 1; i <= p; i++) {
        int r,c,s,d,z;
        cin >> r>>c>>s>>d>>z;
        mp[r-1][c-1] = i;
        shark[i][0] = r-1;
        shark[i][1] = c-1;
        shark[i][2] = s;
        shark[i][3] = d;
        shark[i][4] = z;
    }

    for (int i = 0; i < m ; i++) {
        caught(i);
        moveall();
        if (i == 1) {
            int a = 0;
        }
    }


    cout << sum;
        
}