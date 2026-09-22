/*
전형적인 dfs/bfs문제이다 처음의 경우에 방문처리나 여러가지 신경쓰자 ㅈㅂ
 */
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include<set>
#include<deque>
#include<cmath>
typedef long long ll;
using namespace std;
int dp[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
void dfs(int pt, int y, int x, int& csize, vector<vector<int>>& picture) {
    int m = picture.size();
    int n = picture[0].size();
    for (int i = 0;i < 4;i++) {
        int ny = y + dp[i][0];
        int nx = x + dp[i][1];
        if (ny<0 || ny>=m || nx<0 || nx>=n) {
            continue;
        }
        if (pt == picture[ny][nx]) {
            csize++;
            picture[ny][nx] = -1;
            dfs(pt, ny, nx, csize, picture);
        }
    }
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size = 0;
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < n;j++) {
            if (picture[i][j] > 0) {
                int csize = 1;
                number_of_area++;
                int pt = picture[i][j];
                picture[i][j] = -1;
                dfs(pt, i, j, csize, picture);
                if (csize > max_size) {
                    max_size = csize;
                }
            }
        }
    }



    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size;
    return answer;
}