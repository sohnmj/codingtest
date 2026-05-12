
/*

구현 + BFS 문제

처음에는 컨테이너마다 BFS를 돌려
외부와 연결되는지 확인했는데,
같은 외부 공간을 반복 탐색하게 되어 비효율적이었다.

이 문제는 "외부와 연결 여부"만 중요하므로
각 대상마다 BFS를 하는 대신,
외부 칸(0,0)에서 BFS를 한 번 수행하여
외부와 연결된 모든 공간을 미리 표시하면 된다.

핵심:
- 대상 기준 BFS x
- 외부(소스) 기준 BFS 0

"외부/공기/경계 연결" 문제는
외부에서 한 번 탐색하는 방식 먼저 떠올리기.

*/
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include<queue>
using namespace std;
int dp[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
void doubleAlpabet(vector<vector<int>>& board, int n, int m,int target) {
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (board[i][j] == target) {
                board[i][j] =-1;
            }
        }
    }
}
bool isExternel(vector<vector<int>>board, int n, int m, int x, int y) {
    vector<vector<int>>visited(n + 2, vector<int>(m + 2,0));
    deque<pair<int, int>>dq;
    dq.push_back({ x,y });
    while (!dq.empty()) {
        pair<int,int> cur=dq.front();
        dq.pop_front();
        int cx = cur.first;
        int cy = cur.second;
        if (board[cx][cy] == 0) {
            return true;
        }
        for (int i = 0;i < 4;i++) {
            int nx = cx + dp[i][0];
            int ny = cy + dp[i][1];
            if (board[nx][ny] <= 0&&visited[nx][ny]==0) {
                dq.push_back({ nx,ny });
                visited[nx][ny] = 1;
            }
        }
    }
    return false;
}
void singleAlpabet(vector<vector<int>>& board, int n, int m, int target) {
    vector<pair<int, int>>remove;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (board[i][j] == target) {
                if (isExternel(board, n, m, i, j)) {
                    remove.push_back({ i,j });
                }
            }
        }
    }
    for (auto i : remove) {
        board[i.first][i.second] = -1;
    }

}
int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    int n = storage.size();
    int m = storage[0].size();
    vector<vector<int>>board(n + 2, vector<int>(m + 2,0));
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            board[i + 1][j + 1] = (int)storage[i][j];
        }
    }
    for (string request : requests) {
        if (request.size() == 2) {
            doubleAlpabet(board, n, m, request[0]);
        }
        else {
            singleAlpabet(board, n, m, request[0]);
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (board[i][j] >0) {
                answer++;
            }
        }
    }
    return answer;
}
int main() {
    std::vector<int>vectors = { 0, 2, 3, 3, 1, 2, 0, 0, 0, 0, 4, 2, 0, 6, 0, 4, 2, 13, 3, 5, 10, 0, 1, 5};

    cout<<solution(vectors,3,5);
    

}