
/*
너무 너무 힘든 문제였다.
이문제를 풀기 위해 구현해야하는 기능

1.  0,0좌표 표준화
2.  90도 회전
3.  dfs
4.  맞는지 비교



먼저 dfs를 이용해 게임 보드의 빈 조각과 퍼즐이 있는 보드의 퍼즐 조각을 구해야한다. 이때 조각은 보드 기준의 좌표로 구성되어 있기 떄문에
0,0의 좌표 기준으로 표준화를 시켜줘야한다. 그리고 퍼즐 조각을 90도 씩 회전해가며 빈 조각가 맞는 확인해야한다.
이때 주의할점은 표준화를 한뒤 회전을 시키더라도 표준화가 안된 조각으로 회전 될 수 있기 때문에 회전을 한뒤 반드시 초기화를 해줘야한다.


*/
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
int vis[50][50] = { 0, };
int dp[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
void dfs(vector<vector<int>>board, int x, int y, int r, vector<pair<int, int>>& fg) {
    vis[y][x] = 1;
    int n = board.size();
    fg.push_back({ y,x });
    for (int i = 0; i < 4; i++) {
        int nx = x + dp[i][0];
        int ny = y + dp[i][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (board[ny][nx] == r&&vis[ny][nx]==0) {
                dfs(board, nx, ny, r, fg);
            }
        }
    }

}
void normal(vector<pair<int, int>>& fg) {
    int minx = fg[0].second;
    int miny = fg[0].first;
    for (auto i : fg) {
        minx = min(minx, i.second);
        miny = min(miny, i.first);
    }
    for (auto& i : fg) {
        i.first -= miny;
        i.second -= minx;
    }
 
}
vector<pair<int, int>> r90(vector<pair<int, int>> fg) {
    int n = 0;

   
    for (auto& p : fg) {
        n = max(n, max(p.first, p.second));
    }
    n += 1;  


    vector<pair<int, int>> rotated_fg;

    for (auto& p : fg) {
        int x = p.first;
        int y = p.second;
        rotated_fg.push_back({ y, n - 1 - x });
    }

    return rotated_fg;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = -1;

    //퍼즐 위치 배열
    vector<vector<pair<int, int>>> t_fg;
    //게임보드 공백 배열
    vector<vector<pair<int, int>>> b_fg;
    //게임보드 행 길이
    int n = game_board.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j] == 1 && vis[i][j] == 0) {
                vector < pair<int, int>>fg;
                dfs(table,  j, i, 1, fg);
                t_fg.push_back(fg);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            vis[i][j] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (game_board[i][j] == 0 && vis[i][j] == 0) {
                vector < pair<int, int>>fg;
                dfs(game_board, j, i, 0, fg);
                b_fg.push_back(fg);
            }
        }
    }
    for (auto &i : t_fg) {
        normal(i);
    }
    for (auto& i : b_fg) {
        normal(i);
    }

    int num = b_fg.size();
    vector<int> vib(b_fg.size(), 0);
    answer = 0;
    for (auto i : t_fg) {
        for (int k = 0; k < num;k++) {
            if (vib[k] == 1) {
                continue;
            }
            int boo = 0;
            vector < pair<int, int>>j = b_fg[k];
            for (int t = 0; t < 4; t++) {
                if (i.size() == j.size()) {
                    sort(i.begin(), i.end());
                    sort(j.begin(), j.end());

                    if (i == j) {
                        vib[k] = true;
                        answer += i.size();  
                        boo = 1;
                        break;
                    }
                }
                i = r90(i);
                normal(i);
            }
            if (boo == 1)break;
        }
    }
    return answer;
}
int main() {
    vector<vector<int>> v = {
    {1, 1, 0, 0, 1, 0},
    {0, 0, 1, 0, 1, 0},
    {0, 1, 1, 0, 0, 1},
    {1, 1, 0, 1, 1, 1},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0, 0}
    };


    vector<vector<int>> v1 = {
        {1, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1, 1},
        {0, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0}
    };
    cout<<solution(v,v1);
    

}