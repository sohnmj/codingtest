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
전체적인 틀은 조합을 이용해서 사다리를 설치하는 곳을 찾은 다음 조건에 만족하는지 확인하는 것이다.
여기서 주의할점은 사다리를 설치하고 나면 처음에 구한 사다리를 설치할 수 있던 곳이 불가능해질수도 있다는 것이다. 따라서 설치하기전에 설치 가능한지 계속 확인해줘야한다.
그리고 
    if (d == l) {
        if (check()) {
            cout << l;
            exit(0);
        }
        return;
    }
    이 부분에서 return;을 안시켜줘서 d>l인 경우에도 계속 탐색을 중지하지 않아 시간초과가 되었다.

*/
vector<pair<int, int>>lc;
queue<pair<int, int>>q;
vector<vector<int>>mp(30, vector<int>(10, 0));
int mn = 4;
int n, m, h;
int inst(int j, int i) {
    if (j == 0) {
        if (mp[i][j + 1] == 0) {
            return 1;
        }
    }
    else if (j == n - 2) {
        if (mp[i][j - 1] == 0) {
            return 1;
        }
    }
    else {
        if (mp[i][j + 1] == 0 && mp[i][j - 1] == 0) {
            return 1;
        }
    }
    return 0;
}
int check() {
    int ps = 1;
    for (int i = 0; i < n; i++) {
        int x = i;
        int y = 0;
        while (y != m) {
            if (mp[y][x] == 1) {
                x++;
            }
            else if (x > 0 && mp[y][x - 1] == 1) {
                x--;
            }
            y++;
        }
        if (x != i) {
            return 0;
        }
    }
    return 1;
}
void dfs(int s, int d, int l) {
    if (d == l) {
        if (check()) {
            cout << l;
            exit(0);
        }
        return;
    }
    for (int i = s; i < lc.size(); i++) {

        int x = lc[i].second;
        int y = lc[i].first;
        if (inst(x, y)) {
            mp[y][x] = 1;
            dfs(i + 1, d + 1, l);
            mp[y][x] = 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x, y;

    cin >> n >> h >> m;
    for (int i = 0; i < h; i++) {
        cin >> x >> y;
        mp[x - 1][y - 1] = 1;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (mp[i][j] == 1) continue;
            if (j == 0) {
                if (mp[i][j + 1] == 0) {
                    lc.push_back({ i,j });
                }
            }
            else if (j == n - 2) {
                if (mp[i][j - 1] == 0) {
                    lc.push_back({ i,j });
                }
            }
            else {
                if (mp[i][j + 1] == 0 && mp[i][j - 1] == 0) {
                    lc.push_back({ i,j });
                }
            }

        }
    }
    if (check()) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        dfs(0, 0, i + 1);
    }
    cout << -1;

}