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
dfs를 곁들인 구현문제 문제 잘 읽자
*/
int chain[4][8];
void rotate(int nb, int dir) {
    if (dir == 1) {
        int temp = chain[nb][7];
        for (int i = 7; i > 0; i--) {
            chain[nb][i] = chain[nb][i - 1];
        }
        chain[nb][0] = temp;
    }
    else {
        int temp = chain[nb][0];
        for (int i = 0; i < 7; i++) {
            chain[nb][i] = chain[nb][i + 1];
        }
        chain[nb][7] = temp;
    }
}
int vis[4] = { 0, };
void solution(int nb, int dir) {
    vis[nb] = 1;
    if (nb - 1 >= 0&&vis[nb-1]==0) {
        if (chain[nb][6] == chain[nb - 1][2]) {} /*solution(nb - 1, dir);     */
        else solution(nb - 1, dir * -1);
    }
    if(nb + 1 < 4&&vis[nb+1]==0) {
        if (chain[nb][2] == chain[nb + 1][6]) {}/*solution(nb + 1, dir);*/
        else solution(nb + 1, dir * -1);
    }
    rotate(nb, dir);
}
int score() {
    int sum = 0;
    int n=1;
    for (int i = 0; i < 4; i++) {
        if (chain[i][0] == 1) {
            sum += n;
        }
        n *= 2;
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    for (int i = 0; i < 4; i++) {
        cin >> s;
        for (int j = 0; j < 8; j++) {
            chain[i][j]=s[j]-48;
        }
    }
    int t;
    int nb, dir;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> nb >> dir;
        for (int j = 0; j < 4; j++) {
            vis[j] = 0;
        }
        solution(nb-1, dir);
    }
    int sum = score();
    cout << sum;
    
}