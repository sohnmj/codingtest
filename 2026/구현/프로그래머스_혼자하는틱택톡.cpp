/*조건문 문제 하나의 수로 빙고가 2개가 될 수 있다는 사실을 몰랐다..*/
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include<cmath>

using namespace std;
int findbingo(vector<string> board,char c) {
    int cnt = 0;
    for (int i = 0;i < 3;i++) {
        int isBingo = 1;
        for (int j = 0;j < 3;j++) {
            if (board[i][j] != c) {
                isBingo = 0;
                break;
            }
        }
        if (isBingo== 1) {
            cnt++;
        }
    }
    for (int i = 0;i < 3;i++) {
        int isBingo = 1;
        for (int j = 0;j < 3;j++) {
            if (board[j][i] != c) {
                isBingo = 0;
                break;
            }
        }
        if (isBingo == 1) {
            cnt++;
        }
    }
    int x = -1,y=-1;
    int isBingo = 1;
    for (int i = 0;i < 3;i++) {
        x += 1, y += 1;
        if (board[x][y] != c) {
            isBingo = 0;
            break;
        }
    }
    if (isBingo == 1) {
        cnt++;
    }

    x = -1, y = 3;
    isBingo = 1;
    for (int i = 0;i < 3;i++) {
        x += 1, y -= 1;
        if (board[y][x] != c) {
            isBingo = 0;
            break;
        }
    }
    if (isBingo == 1) {
        cnt++;
    }
    return cnt;
}
int solution(vector<string> board) {
    int answer = 1;
    int Xcnt = 0, Ocnt = 0;
    for (auto row : board) {
        for (char ch : row) {
            if (ch == 'X') {
                Xcnt++;
            }
            else if (ch == 'O') {
                Ocnt++;
            }
        }
    }

    int Xbingo = findbingo(board, 'X');
    int Obingo = findbingo(board, 'O');
    if (Xcnt > Ocnt || Ocnt - Xcnt > 1) {
        answer = 0;
        return answer;
    }
    if (Xbingo && Obingo) {
        answer = 0;
        return answer;
    }
    if (Xbingo * Obingo != 0) {
        answer = 0;
        return answer;
    }
    if (Obingo == 1&&Ocnt-Xcnt!=1) {
        answer = 0;
        return answer;
    }
    if (Xbingo == 1 && Ocnt - Xcnt != 0) {
        answer = 0;
        return answer;
    }
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

    cout<<solution( { "O.X", ".O.", "..O" });
    cout << "안영하";
}