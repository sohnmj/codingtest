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
인접 노드를 구하는 것만 뺴면 그냥 단순한 dfs문제였다. 
인접노드를 구하기 위해서 위,아래,오른쪽,왼쪽으로 이동하는 로직을 각각 구했는데 코드가 너무 길어진 것 같다.
그냥 판자체를 90도씩 돌려서 한 방향으로만 이동하는 로직을 짰다면 더 코드는 짧았을 것 같다.

*/
int dt[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int mx = 0;
void push(vector<vector<int>>& board, int n,int dp)
{ 
    if (dp == 0) {
        for (int i = 0; i < n; i++) {
            //합체
            for (int j = 0; j < n - 1; j++) {
                if (board[i][j] != 0) {
                    int k = j + 1;
                    while (k < n && board[i][k] == 0) k++;
                    if (k < n) {
                        if (board[i][j] == board[i][k]) {
                            board[i][j] *= 2;
                            board[i][k] = 0;
                            j = k;
                        }
                    }
                }
            }
            //푸쉬
            for (int j = 0; j <= n - 1; j++) {
                if (board[i][j] == 0) {
                    int k = j + 1;
                    while (k < n && board[i][k]==0)k++;
                    if (k < n) {
                        board[i][j] = board[i][k];
                        board[i][k] = 0;
                    }
                }
            }
        }
    }

    else if (dp == 1) {
        for (int i = 0; i < n; i++) {
            //합체
            for (int j = n-1; j > 0; j--) {
                if (board[i][j] != 0) {
                    int k = j - 1;
                    while (k >=0 && board[i][k] == 0) k--;
                    if (k >=0) {
                        if (board[i][j] == board[i][k]) {
                            board[i][j] *= 2;
                            board[i][k] = 0;
                            j = k;
                        }
                    }
                }
            }
            //푸쉬
            for (int j = n-1; j >= 0; j--) {
                if (board[i][j] == 0) {
                    int k = j - 1;
                    while (k >=0 && board[i][k] == 0)k--;
                    if (k >=0) {
                        board[i][j] = board[i][k];
                        board[i][k] = 0;
                    }
                }
            }
        }
    }
    else if (dp == 2) {
        for (int j = 0; j < n; j++) {
            //합체
            for (int i = 0; i < n - 1; i++) {
                if (board[i][j] != 0) {
                    int k = i + 1;
                    while (k < n && board[k][j] == 0) k++;
                    if (k < n) {
                        if (board[i][j] == board[k][j]) {
                            board[i][j] *= 2;
                            board[k][j] = 0;
                            i = k;
                        }
                    }
                }
            }
            //푸쉬
            for (int i = 0; i <= n - 1; i++) {
                if (board[i][j] == 0) {
                    int k = i + 1;
                    while (k < n && board[k][j] == 0)k++;
                    if (k < n) {
                        board[i][j] = board[k][j];
                        board[k][j] = 0;
                    }
                }
            }
        }
    }
    else if (dp == 3) {
        for (int j = 0; j < n; j++) {
            //합체
            for (int i = n-1; i > 0; i--) {
                if (board[i][j] != 0) {
                    int k = i - 1;
                    while (k >=0 && board[k][j] == 0) k--;
                    if (k >=0) {
                        if (board[i][j] == board[k][j]) {
                            board[i][j] *= 2;
                            board[k][j] = 0;
                            i = k;
                        }
                    }
                }
            }
            //푸쉬
            for (int i = n-1; i >=0; i--) {
                if (board[i][j] == 0) {
                    int k = i -1;
                    while (k >=0 && board[k][j] == 0)k--;
                    if (k >=0) {
                        board[i][j] = board[k][j];
                        board[k][j] = 0;
                    }
                }
            }
        }
    }
}
int count(vector<vector<int>> board,int n)
{
    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mx < board[i][j]) {
                mx = board[i][j];
            }
        }
    }
    return mx;
}

void dfs(vector<vector<int>> board,int n, int d) {
    if (d == 5) {
        int c = count(board, n);
        if (mx < c) {
            mx = c;
        }
    }
    else {
        for (int i = 0; i < 4; i++) {
            vector<vector<int>>board1 = board;
            push(board1, n,i);
            dfs(board1, n, d + 1);

            
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    dfs(board, n, 0);
    cout << mx;
}