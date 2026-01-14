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
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int dp[500][500] = {1e9,};
    int n = triangle.size();
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; i++) {
        int y = i - 1;
        for (int j = 0; j <= i; j++) {
            int x = j-1;
            if (x >= 0 && x <= i) {
                dp[i][j] = max(dp[i][j], dp[y][x] + triangle[i][j]);
            }
            x++;
            if (x >= 0 && x <= i) {
                dp[i][j] = max(dp[i][j], dp[y][x] + triangle[i][j]);
            }
            if (i == n - 1) {
                if (answer < dp[i][j]) {
                    answer = dp[i][j];
                }
            }
        }
    }
    return answer;
}
int main() {
    vector<vector<int>> v = {
      {7},
      {3, 8},
      {8, 1, 0},
      {2, 7, 4, 4},
      {4, 5, 2, 6, 5}
    };
    cout<<solution(v);
}