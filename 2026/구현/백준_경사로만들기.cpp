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
너무 스택에 집착하다보니 문제를 빙빙들러서 푼 느낌이었다. 단순히 cnt(같은 높이를 가진 벽 수)를 활용하여 풀었으면 더 간단한 경우의 수로 풀었을 것 같다.

*/
void clearstack(stack<int>& st) {
    while (!st.empty()) {
        st.pop();
    }
}
int countWay(vector<vector<int>> board, int l) {
    int ct = 0;
    int n = board.size();
    stack<int>st;
    for (int i = 0; i < n; i++) {
        int bo = 1;
        int pre=0;
        for (int j = 0; j < n; j++) {
            if (st.empty()) {
                if(pre==0||pre==board[i][j]) st.push(board[i][j]); 
                else if (pre - board[i][j] == 1) {
                    int center = board[i][j];
                    clearstack(st);
                    while (j < n) {
                        if (center != board[i][j]) {
                            break;
                        }
                        st.push(board[i][j]);
                        j++;
                    }
                    if (st.size() < l) {
                        bo = 0;
                        break;
                    }
                    pre = st.top();
                    for (int k = 0; k < l; k++)st.pop();
                    j--;
                }
                else {
                    bo = 0;
                    break;
                }
            }
            else {
                if (st.top() > board[i][j]) {
                    if(st.top()-board[i][j]!=1){
                        bo = 0;
                        break;
                    }
                    int center = board[i][j];
                    clearstack(st);
                    while (j < n) {
                        if (center != board[i][j]) {
                            break;
                        }
                        st.push(board[i][j]);
                        j++;
                    }
                    if (st.size() < l) {
                        bo = 0;
                        break;
                    }
                    pre = st.top();
                    for (int k = 0; k < l; k++)st.pop();                    
                    j--;
                }
                else if (st.top() < board[i][j]) {
                    if (st.top() - board[i][j] != -1) {
                        bo = 0;
                        break;
                    }
                    else {
                        if (st.size() < l) {
                            bo = 0;
                            break;
                        }
                        clearstack(st);
                        st.push(board[i][j]);
                    }
                }
                else st.push(board[i][j]);
            }
        }
        if (bo == 1) {
            ct++;
        }
        clearstack(st);
    }
    return ct;
}
int main() {
    int n,l;
    cin >> n>>l;
    vector<vector<int>> board(n, vector<int>(n));
    vector<vector<int>> board1(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            board1[j][i] = board[i][j];

    }
    cout << countWay(board, l) +countWay(board1, l);
}