/*bfs.*/
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include<cmath>

using namespace std;
int visited[100][100];
int gx, gy;
int dt[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int bfs(int x,int y,vector<string>board) {
    deque < vector<int>>dq;
    int n = board.size();
    int m = board[0].size();
    visited[x][y] = 1;
    dq.push_back({ x,y,0 });
    while (!dq.empty()) {
        vector<int>cur = dq.front();
        dq.pop_front();
        int x = cur[0];
        int y = cur[1];
        int cnt = cur[2];
        if (x == gx && y == gy) {
            return cnt;
        }
        for (int i = 0;i < 4;i++) {
            int dx = dt[i][0], dy = dt[i][1];
            int nx = x , ny = y ;
            int ncnt = cnt;
            while (!(nx + dx < 0 || nx + dx >= n || ny + dy < 0 || ny + dy >= m || board[nx + dx][ny + dy] == 'D')) {
                nx += dx;
                ny += dy;
                
            }
            if ((nx == x && ny == y)||(visited[nx][ny]==1)) {
                continue;
            }
            visited[nx][ny] =1;
            dq.push_back({ nx,ny,++ncnt });
        }
    }
    return -1;
}
int solution(vector<string> board) {
    int answer = 0;
    int x, y;
    for (int i = 0;i < board.size();i++) {
        for (int j = 0;j < board[i].size();j++) {
            if (board[i][j] == 'R') {
                board[i][j] = '.';
                x = i;
                y = j;
            }
            else if (board[i][j] == 'G') {
                gx = i;
                gy = j;
            }
        }
    }
    answer=bfs(x, y, board);
    return answer;
}

int main() {
    vector<vector<string>> plans = {
        {"science", "12:40", "50"},
        {"music", "12:20", "40"},
        {"history", "14:00", "30"},
        {"computer", "12:30", "100"}
    };

    vector<vector<int>> b = {
        {1, 2, 1, 2},
        {2, 1, 2, 1}
    };

    cout<<solution( { "...D..R", ".D.G...", "....D.D", "D....D.", "..D...." });
    cout << "╬х©╣го";
}