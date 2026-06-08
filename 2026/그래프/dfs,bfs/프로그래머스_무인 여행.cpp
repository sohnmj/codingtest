/*bfs.*/
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include<cmath>
int dt[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
using namespace std;
void bfs(int sy, int sx, vector<string>& maps, vector<int>& answer, vector<vector<int>>&visited) {
    int row = maps.size();
    int col = maps[0].size();
    int sum = maps[sy][sx]-48;
  
    deque<vector<int>> dq;
    dq.push_back({ sx,sy });
   
    /*¤Ð¤©¤¤.*/
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include<cmath>
    int dt[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
    using namespace std;
    void bfs(int sy, int sx, vector<string>&maps, vector<int>&answer, vector<vector<int>>&visited) {
        int row = maps.size();
        int col = maps[0].size();
        int sum = maps[sy][sx] - 48;

        deque<vector<int>> dq;
        dq.push_back({ sx,sy });
        visited[sy][sx] = 1;
        while (!dq.empty()) {
            vector<int> cur = dq.front();
            dq.pop_front();
            int cx = cur[0], cy = cur[1];
            for (int i = 0;i < 4;i++) {
                int nx = cx + dt[i][0], ny = cy + dt[i][1];
                if (nx >= 0 && nx < col && ny >= 0 && ny < row) {
                    if (maps[ny][nx] != 'X' && visited[ny][nx] == 0) {
                        sum += (maps[ny][nx] - 48);
                        visited[ny][nx] = 1;
                        dq.push_back({ nx,ny });

                    }
                }
            }
        }
        answer.push_back(sum);
    }
    vector<int> solution(vector<string> maps) {
        vector<int> answer;
        int row = maps.size();
        int col = maps[0].size();
        vector<vector<int>>visited(row, vector<int>(col, 0));
        for (int i = 0;i < row;i++) {
            for (int j = 0;j < col;j++) {
                if (maps[i][j] != 'X' && visited[i][j] == 0) {
                    bfs(i, j, maps, answer, visited);
                }
            }
        }
        sort(answer.begin(), answer.end());
        if (answer.size() == 0) {
            answer.push_back(-1);
        }
        return answer;
    }int main() {
    vector<string> plans = {
       "SOOOL","XXXXO","OOOOO","OXXXX","OOOOE"
    };

    vector<vector<int>> b = {
        {1, 2, 1, 2},
        {2, 1, 2, 1}
    };

    cout<<solution( plans);
    cout << "¾È¿µÇÏ";
}