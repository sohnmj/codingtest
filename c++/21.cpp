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

    // �ʱ� ���� (�κ� ���� ����)
    q.push({ 0, 0, 0, 1, 0, 1 });
    visited.insert({ 0, 0, 0, 1 });

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        // ���� ����
        if ((cur.y1 == n - 1 && cur.x1 == n - 1) || (cur.y2 == n - 1 && cur.x2 == n - 1)) {
            return cur.time;
        }

        // �����¿� �̵�
        for (int i = 0; i < 4; i++) {
            int ny1 = cur.y1 + dy[i];
            int nx1 = cur.x1 + dx[i];
            int ny2 = cur.y2 + dy[i];
            int nx2 = cur.x2 + dx[i];

            if (ny1 < 0 || ny1 >= n || nx1 < 0 || nx1 >= n || ny2 < 0 || ny2 >= n || nx2 < 0 || nx2 >= n) continue;
            if (board[ny1][nx1] == 1 || board[ny2][nx2] == 1) continue;

            // ��ǥ ����
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

        // ȸ�� ����
        if (cur.dir == 1) {  // ���� ������ ��
            // ���� ȸ��
            if (cur.y1 > 0 && board[cur.y1 - 1][cur.x1] == 0 && board[cur.y2 - 1][cur.x2] == 0) {
                // ���� �� �������� �ð� ���� ȸ�� (���� -> ����)
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

                // ������ �� �������� �ݽð� ���� ȸ��
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
            // �Ʒ��� ȸ��
            if (cur.y1 < n - 1 && board[cur.y1 + 1][cur.x1] == 0 && board[cur.y2 + 1][cur.x2] == 0) {
                // ���� �� �������� �ݽð� ���� ȸ��
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
                // ������ �� �������� �ð� ���� ȸ��
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
        else {  // ���� ������ �� (dir == -1)
            // ���� ȸ��
            if (cur.x1 > 0 && board[cur.y1][cur.x1 - 1] == 0 && board[cur.y2][cur.x2 - 1] == 0) {
                // ���� �� �������� �ݽð� ���� ȸ�� (���� -> ����)
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

                // �Ʒ��� �� �������� �ð� ���� ȸ��
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
            // ������ ȸ��
            if (cur.x1 < n - 1 && board[cur.y1][cur.x1 + 1] == 0 && board[cur.y2][cur.x2 + 1] == 0) {
                // ���� �� �������� �ð� ���� ȸ��
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

                // �Ʒ��� �� �������� �ݽð� ���� ȸ��
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

    return -1;  // ���� ���� ���
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