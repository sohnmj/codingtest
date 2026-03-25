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
#include <iomanip> 
using namespace std;
/*
dp문제 였다.
다른 dp와 다른점은 전에 이동했던 방향으로 이동하지 못한다.
그렇기 떄문에 방향 정보 또한 저장해야한다.
그래서 움직일 수 있는 방향의 수만큼을 dp에 저장했고 
그 정보를 가지고  다음 칸의 최소의 수를 찾았다.
*/
int dp[6][6][3];
int mp[6][6];
int m, n;
int dt[4][2] = {  { -1,-1 },{-1,0},{-1,1} };
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mp[i][j];
			for (int k = 0; k< 3; k++) {
				dp[i][j][k] = 1000000000;
			}
		}
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < 3; i++) {
			dp[0][j][i] = mp[0][j];
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = i, y = j;
			for (int k = 0; k < 3; k++) {
				for (int t = 0; t < 3; t++) {
					if (t == k) {
						continue;
					}
					int nx = x + dt[t][0], ny = y + dt[t][1];
					if (0 <= nx && nx < n && 0 <= ny && ny < m) {
						if (dp[i][j][k] > dp[nx][ny][t] + mp[i][j]) {
							dp[i][j][k] = dp[nx][ny][t] + mp[i][j];
						}
					}
				}
			}
		}
	}
	int sum = 1000000000;
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < 3; i++) {
			if (sum > dp[n - 1][j][i]) {
				sum = dp[n - 1][j][i];
			}
		}
	}
	cout<<sum;
}