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
/*문제의 설명을 너무 대충 읽는 거 같다 오른쪽과 아래쪽으로만 가야 되는 조건을 읽었다면 더 빨리 풀었을 것 같다.
나중에 보니 현재 위치에 도달할 수 있는 이전의 위치라면 항상 최단거리라는 것을 알게 되었고 
그러면 현재코드에서 dp[i][j][0]값과 이 값을 이용한 비교는 의미가 없는 내용이기에 뺴도 될 것 같다.*/
using namespace std;
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    set<vector<int>>s;
    int dp[100][100][2];
    for (auto i : puddles) {
        s.insert(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) {
                dp[i][j][0] = 0;
                dp[i][j][1] = 1;
                continue;
            }
            dp[i][j][0] = n * m;
            dp[i][j][1] = 0;
            int x = j;
            int y = i - 1;
            if (x > 0 && y > 0 && !s.count({ x,y })) {
                dp[i][j][0] = dp[y][x][0] + 1;
                dp[i][j][1] = dp[y][x][1];
            }
            x = j - 1;
            y = i;
            if (x > 0 && y > 0 && !s.count({ x,y })) {
                if (dp[i][j][0] == dp[y][x][0] + 1) {
                    dp[i][j][1] = (dp[i][j][1] + dp[y][x][1]) % 1000000007;
                }
                if (dp[i][j][0] > dp[y][x][0] + 1) {
                    dp[i][j][0] = dp[y][x][0] + 1;
                    dp[i][j][1] = dp[y][x][1];
                }
            }
        }
    }
    return dp[n][m][1];
}
int main() {
    vector<vector<int>> v = {
        {2,2}
    };
    cout<<solution(4,3,v);
}