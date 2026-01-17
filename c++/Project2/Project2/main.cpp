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
/*그냥 벽을 느낀 문제였다. 이 문제의 핵심적인 어려움은 BFS를 수행할 수 있는 올바른 탐색 환경을 구성하는 것이라고 생각한다.
단순히 BFS 자체는 어렵지 않지만, 캐릭터가 이동할 수 있는 경로를 어떻게 표현하느냐가 문제의 본질이다.

다른 사람의 풀이를 참고하면서, 캐릭터의 이동 경로를 2차원 좌표 공간으로 명확하게 표현해야 한다는 점을 알게 되었다.
하지만 단순히 좌표를 그대로 사용하면 문제가 발생한다.

직사각형의 테두리만을 따라 이동해야 하는데, 좌표를 그대로 그리다 보면
ㄷ자 형태의 경로가 생기게 되고, 이 경우 BFS 탐색 시 의도하지 않은 내부를 직선(I)처럼 가로질러 통과하는 문제가 발생한다.

이를 해결하기 위해 모든 좌표의 값을 2배로 확장하였다.
좌표를 2배로 늘리면 테두리와 내부가 명확히 분리되어,
BFS가 내부를 통과하지 않고 직사각형의 테두리만 정확히 따라 이동할 수 있게 된다.
1 1                1 1 1
1 1  ->            1
                   1 1 1
직사각형의 좌표 값을 2배하여 문제점을 해결하는 걸 배운 것 같다.
*/
using namespace std;

int dp[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    int mp[101][101] = { 0, };
    for (auto i : rectangle) {
        int x1 = i[0] * 2;
        int y1 = i[1] * 2;
        int x2 = i[2] * 2;
        int y2 = i[3] * 2;
        for (int j = y1; j <= y2; j++) {
            for (int k = x1; k <= x2; k++) {
                if (x1 < k && k < x2 && y1 < j && j < y2) {
                    mp[j][k] = -1;
                }
                else if(mp[j][k]==0) {
                    mp[j][k] = 1;
                }
            }
        }
        

    }
    int vis[101][101] = { 0, };
    queue<vector<int>>que;
    que.push({ characterX * 2,characterY * 2,0 });
    vis[characterY * 2][characterX * 2] = 1;
    while (!que.empty()) {
        vector<int>cur = que.front();
        que.pop();
        int x = cur[0], y = cur[1], d = cur[2];
        int nx, ny;
        if (x == 2 * itemX && y == 2 * itemY) {
            return d / 2;
        }
        for (int i = 0; i < 4; i++) {
            nx = x + dp[i][0];
            ny = y + dp[i][1];
            if (1 <= nx && nx <= 100 && 1 <= ny && ny <= 100) {
                if (mp[ny][nx] == 1 && vis[ny][nx] == 0) {
                    que.push({ nx,ny,d + 1 });
                    vis[ny][nx] = 1;
                }
            }
        }
    }
    return answer;
}
int main() {
    vector<vector<int>> v = {
    {1, 1, 7, 4},
    {3, 2, 5, 5},
    {4, 3, 6, 9},
    {2, 6, 8, 8}
    };
    cout<<solution( v,1,3,7,8);
}