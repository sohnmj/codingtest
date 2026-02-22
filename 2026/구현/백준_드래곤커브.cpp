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
많이 고민한만큼 풀이법이 생각 났던 것 같다. 가장 큰 핵심은 드래곤 커브 세대가 몇인지에 상관없이 기준 드래곤 커브에서 세대에 맞춰 방향에 따라서 돌리기 만 하면 된다.
회전하는 것을 구현하는데 시간이 생각보다 많이 걸렸다.
사각형을 세는 것은 생각보다 간단한 풀이였다.

*/
vector<pair<int,int>> arr[11];
set<pair<int, int>> lc;
int rc[4][2] = { {0,0},{1,0},{0,1},{1,1} };
void rotate(int cx,int cy,int x,int y,vector<pair<int,int>>&arr1) {
    int dx = cy-y;
    int dy = -(cx - x);
    arr1.push_back({ cx + dx,cy + dy });

}
void rotate1(int cx, int cy, int x, int y,int n, vector<pair<int, int>>& arr1) {
    int dx = cy - y;
    int dy = -(cx - x);
    arr1[n].first = cx + dx;
    arr1[n].second = cy + dy;


}
vector<pair<int,int>> rotateall(int cx, int cy,int n,int dcn) {
    int len = arr[dcn].size();
    vector<pair<int, int>>dc1=arr[dcn];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < len; j++) {
            rotate1(cx, cy, dc1[j].first, dc1[j].second,j, dc1);
        }
    }
    return dc1;
}
void next(int n) {
    int len = arr[n - 1].size();
    int cx = arr[n - 1][len - 1].first;
    int cy = arr[n - 1][len - 1].second;
    for (int i = 0; i < len; i++) {
        arr[n].push_back(arr[n - 1][i]);
    }
    for (int i = len - 2; i >= 0; i--) {
        int x = arr[n - 1][i].first;
        int y = arr[n - 1][i].second;
        rotate(cx, cy, x, y, arr[n]);
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    arr[0].push_back({ 0,0 });
    arr[0].push_back({ 1,0 });
    int n;
    cin >> n;
    int x, y;
    int dcn, dr;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> dr >> dcn;
        for (int j = 1; j <= dcn; j++) {
            if (arr[j].size() == 0) {
                next(j);
            }
        }
        //회전
        vector<pair<int, int>>dc = rotateall(arr[dcn][0].first, arr[dcn][0].second, 4 - dr, dcn);
        //자리 찾아가기
        int dx = x - arr[dcn][0].first;
        int dy = y - arr[dcn][0].second;
        for (auto& i : dc) {
            i.first += dx;
            i.second += dy;
        }

        for (auto i : dc) {
            {
                lc.insert({ i.first ,i.second });
            }
        }

    }
    int ct = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            int rct = 1;
            for (int k = 0; k < 4; k++) {
                int x = i + rc[k][0];
                int y = j + rc[k][1];
                if (!lc.count({ x,y })) {
                    rct = 0;
                    break;
                }
            }
            if (rct == 1) {
                ct++;
            }
        }
    }
    cout << ct;
    /*for (auto i : lc) {
        cout << i.first << " " << i.second << endl;
    }*/
}