/*힌트를 먼저 보고 풀어서 그런지 구현하는데는 한세월 걸렸지만 정답 배열을 정렬만 했다면 맞은 문제였다. 전체적으로 dfs를 이용하여 사이클을 찾았고 나는 재귀를 이용해서 찾았는데 보니깐 
visited의 크기가 500*500*4여서 재귀보단 반복문이 안정했을 것 같다. 게다가 분기점이 한개로 정해지기 떄문에 반복문으로 구현하기 더 알맞는 것 도 있었다.*/
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include<cmath>
#include<queue>
#include <unordered_map>
#include<set>
#include<iostream>
typedef long long ll;
using namespace std;
int row,col;
int visited[500][500][4];
vector<int> answer;
int dt[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int change_dir(int x, int y,int dir, vector<string>& grid) {
    if (grid[x][y] == 'L') {
        return (dir + 3) % 4;
    }
    else if (grid[x][y] == 'R') {
        return (dir + 1) % 4;
    }
    else {
        return (dir) % 4;
    }
}
void dfs(int x, int y,int dir, int tx, int ty,int d, int td, vector<string>& grid) {
    int ndir = change_dir(x, y, dir, grid);
    if (x == tx && y == ty&&ndir==td) {
        
        visited[x][y][ndir] = 1;
        d++;
        answer.push_back(d);
    }
    else {
        if (!visited[x][y][ndir]) {
            visited[x][y][ndir] = 1;
            int nx = (x + dt[ndir][0] + row) % row;
            int ny = (y + dt[ndir][1] + col) % col;
            dfs(nx, ny, ndir, tx, ty, d + 1,td, grid);
        }
    }
}
vector<int> solution(vector<string> grid) {

    row= grid.size();
     col = grid[0].length();
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < col;j++) {
            for (int k = 0;k < 4;k++) {

                if (!visited[i][j][k]) {
                    visited[i][j][k] = 1;
                    int nx = (i + dt[k][0]+row)%row;
                    int ny = (j + dt[k][1]+col)%col;
                    dfs(nx, ny, k, i, j,0,k, grid);
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
int main() {
    vector<vector<int>>users = { {40, 10000},{25, 10000} };
    vector<int> plans = {
0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1
    };

    vector<int>ans=solution({ "SL","LR" });
    for (int i : ans) {
        cout << i <<" ";
    }
}