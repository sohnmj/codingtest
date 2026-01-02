#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

struct State {
    int y1, x1, y2, x2, time, dir;
};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int solution(vector<vector<int>> board) {
    int n = board.size();
    queue<State> q;
    set<tuple<int, int, int, int>> visited;

    // 초기 상태 (로봇 가로 방향)
    q.push({ 0, 0, 0, 1, 0, 1 });
    visited.insert({ 0, 0, 0, 1 });

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        // 도착 조건
        if ((cur.y1 == n - 1 && cur.x1 == n - 1) || (cur.y2 == n - 1 && cur.x2 == n - 1)) {
            return cur.time;
        }

        // 상하좌우 이동
        for (int i = 0; i < 4; i++) {
            int ny1 = cur.y1 + dy[i];
            int nx1 = cur.x1 + dx[i];
            int ny2 = cur.y2 + dy[i];
            int nx2 = cur.x2 + dx[i];

            if (ny1 < 0 || ny1 >= n || nx1 < 0 || nx1 >= n || ny2 < 0 || ny2 >= n || nx2 < 0 || nx2 >= n) continue;
            if (board[ny1][nx1] == 1 || board[ny2][nx2] == 1) continue;

            // 좌표 정렬
            int ay = ny1, ax = nx1, by = ny2, bx = nx2;
            if (ay > by || (ay == by && ax > bx)) {
                swap(ay, by);
                swap(ax, bx);
            }

            if (visited.count({ ay, ax, by, bx }) == 0) {
                visited.insert({ ay, ax, by, bx });
                q.push({ ny1, nx1, ny2, nx2, cur.time + 1, cur.dir });
            }
        }

        // 회전 로직
        if (cur.dir == 1) {  // 가로 방향일 때
            // 위쪽 회전
            if (cur.y1 > 0 && board[cur.y1 - 1][cur.x1] == 0 && board[cur.y2 - 1][cur.x2] == 0) {
                // 왼쪽 끝 기준으로 시계 방향 회전 (가로 -> 세로)
                int ay = cur.y1 - 1, ax = cur.x1;
                int by = cur.y1, bx = cur.x1;
                if (ay > by || (ay == by && ax > bx)) {
                    swap(ay, by);
                    swap(ax, bx);
                }
                if (visited.count({ ay, ax, by, bx }) == 0) {
                    visited.insert({ ay, ax, by, bx });
                    q.push({ cur.y1 - 1, cur.x1, cur.y1, cur.x1, cur.time + 1, -1 });
                }

                // 오른쪽 끝 기준으로 반시계 방향 회전
                ay = cur.y2 - 1; ax = cur.x2;
                by = cur.y2; bx = cur.x2;
                if (ay > by || (ay == by && ax > bx)) {
                    swap(ay, by);
                    swap(ax, bx);
                }
                if (visited.count({ ay, ax, by, bx }) == 0) {
                    visited.insert({ ay, ax, by, bx });
                    q.push({ cur.y2 - 1, cur.x2, cur.y2, cur.x2, cur.time + 1, -1 });
                }
            }
            // 아래쪽 회전
            if (cur.y1 < n - 1 && board[cur.y1 + 1][cur.x1] == 0 && board[cur.y2 + 1][cur.x2] == 0) {
                // 왼쪽 끝 기준으로 반시계 방향 회전
                int ay = cur.y1, ax = cur.x1;
                int by = cur.y1 + 1, bx = cur.x1;
                if (ay > by || (ay == by && ax > bx)) {
                    swap(ay, by);
                    swap(ax, bx);
                }
                if (visited.count({ ay, ax, by, bx }) == 0) {
                    visited.insert({ ay, ax, by, bx });
                    q.push({ cur.y1, cur.x1, cur.y1 + 1, cur.x1, cur.time + 1, -1 });
                }
                // 오른쪽 끝 기준으로 시계 방향 회전
                ay = cur.y2; ax = cur.x2;
                by = cur.y2 + 1; bx = cur.x2;
                if (ay > by || (ay == by && ax > bx)) {
                    swap(ay, by);
                    swap(ax, bx);
                }
                if (visited.count({ ay, ax, by, bx }) == 0) {
                    visited.insert({ ay, ax, by, bx });
                    q.push({ cur.y2, cur.x2, cur.y2 + 1, cur.x2, cur.time + 1, -1 });
                }
            }
        }
        else {  // 세로 방향일 때 (dir == -1)
            // 왼쪽 회전
            if (cur.x1 > 0 && board[cur.y1][cur.x1 - 1] == 0 && board[cur.y2][cur.x2 - 1] == 0) {
                // 위쪽 끝 기준으로 반시계 방향 회전 (세로 -> 가로)
                int ay = cur.y1, ax = cur.x1 - 1;
                int by = cur.y1, bx = cur.x1;
                if (ay > by || (ay == by && ax > bx)) {
                    swap(ay, by);
                    swap(ax, bx);
                }
                if (visited.count({ ay, ax, by, bx }) == 0) {
                    visited.insert({ ay, ax, by, bx });
                    q.push({ cur.y1, cur.x1 - 1, cur.y1, cur.x1, cur.time + 1, 1 });
                }

                // 아래쪽 끝 기준으로 시계 방향 회전
                ay = cur.y2; ax = cur.x2 - 1;
                by = cur.y2; bx = cur.x2;
                if (ay > by || (ay == by && ax > bx)) {
                    swap(ay, by);
                    swap(ax, bx);
                }
                if (visited.count({ ay, ax, by, bx }) == 0) {
                    visited.insert({ ay, ax, by, bx });
                    q.push({ cur.y2, cur.x2 - 1, cur.y2, cur.x2, cur.time + 1, 1 });
                }
            }
            // 오른쪽 회전
            if (cur.x1 < n - 1 && board[cur.y1][cur.x1 + 1] == 0 && board[cur.y2][cur.x2 + 1] == 0) {
                // 위쪽 끝 기준으로 시계 방향 회전
                int ay = cur.y1, ax = cur.x1;
                int by = cur.y1, bx = cur.x1 + 1;
                if (ay > by || (ay == by && ax > bx)) {
                    swap(ay, by);
                    swap(ax, bx);
                }
                if (visited.count({ ay, ax, by, bx }) == 0) {
                    visited.insert({ ay, ax, by, bx });
                    q.push({ cur.y1, cur.x1, cur.y1, cur.x1 + 1, cur.time + 1, 1 });
                }

                // 아래쪽 끝 기준으로 반시계 방향 회전
                ay = cur.y2; ax = cur.x2;
                by = cur.y2; bx = cur.x2 + 1;
                if (ay > by || (ay == by && ax > bx)) {
                    swap(ay, by);
                    swap(ax, bx);
                }
                if (visited.count({ ay, ax, by, bx }) == 0) {
                    visited.insert({ ay, ax, by, bx });
                    q.push({ cur.y2, cur.x2, cur.y2, cur.x2 + 1, cur.time + 1, 1 });
                }
            }
        }
    }

    return -1;  // 도착 못한 경우
}


int main() {
    vector<vector<int>> board = { {0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0} };
    cout<<solution(board);
    
    int y1 = 1;
    int x1 = 1;
    int y2 =0;
    int x2 = 0;
    
    double avgY = (y1 + y2) / 2.0;
    double avgX = (x1 + x2) / 2.0;

    visited.insert({ avgY, avgX });
     y1 = 0;
     x1 = 0;
     y2 = 1;
     x2 = 1;
     avgY = (y1 + y2) / 2.0;
    avgX = (x1 + x2) / 2.0;
    cout << visited.count({ avgY, avgX });
}