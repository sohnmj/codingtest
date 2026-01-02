#include<iostream>
#include<vector>
using namespace std;

int country[50][50];
int visited[50][50] = { 0 ,};
int L, R;
int dx[4] = { 1,0, -1,0 };
int dy[4] = { 0,1,0,-1 };

vector<pair<int, int>> * arr;
void dfs(int n, int y, int x, int cn) {
    arr[cn].push_back(make_pair(y, x));
    visited[y][x] = cn;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (visited[ny][nx] == 0) {
                int dif = abs(country[y][x] - country[ny][nx]);
                if (dif >= L && dif <= R) {
                    dfs(n, ny, nx, cn);
                }
            }
        }
    }
}

int check(int n) {
    int cn = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == 0) {              
                dfs(n,i,j, cn);
                cn++;
            }
        }
    }
    if (cn == n * n+1) {
        return 0;
    }
    int sum ,N;
    for (int i = 1; i < cn; i++) {
        sum = 0;
        N = arr[i].size();
        for (auto inx : arr[i]) {
            int x = inx.second;
            int y = inx.first;
            sum += country[y][x];
            
        }
        for (auto inx : arr[i]) {
            int x = inx.second;
            int y = inx.first;
            country[y][x] = sum / N;
        }

    }
    for (int i = 1; i < cn; i++) {
        arr[i].clear();

    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
    return 1;
}

int main() {
    

    int n;
    
    int da=0;
    cin >> n;
    cin >> L >> R;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> country[i][j];
        }
    }
    arr = new vector<pair<int, int>>[n * n+1];
    while (check(n)) {
        
        da++;
    }
    cout << da;

}