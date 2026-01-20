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
/*
처음 문제에 접근할 때 아이디어 자체는 나쁘지 않았다.

1. **아이디어 요약**
   - 괄호 안의 숫자 개수와 시작 위치를 기준으로 DP 점화식을 세움
   - 구간 내 숫자를 두 그룹으로 나누고 각각의 최댓값을 계산한 뒤 합하면
     그 구간의 최댓값을 얻을 수 있다는 접근

2. **문제점**
   - '-' 연산자가 있을 때 단순히 그룹의 최댓값을 합하는 방식으로는
     정확한 최댓값을 구할 수 없음
   - '-' 연산에서는 오른쪽 구간의 **최솟값을 빼야** 최댓값이 나오는 특성이 있음

3. **해결**
   - 처음부터 '-' 연산을 고려하지 않고,
     각 구간의 **최댓값과 최솟값을 모두 계산**하도록 DP를 확장
   - '-' 연산자가 나오면 오른쪽 구간의 최솟값을 빼고,
     '+' 연산자는 기존처럼 단순히 더하는 방식 적용

4. **결론**
   - 괄호 구간을 나누고, 최댓값/최솟값을 구분해서 계산하는 접근이 핵심
   - '-' 연산자를 어떻게 처리할지 이해하는 것이 문제 해결 포인트
*/
using namespace std;
int solution(vector<string> arr)
{
    int answer = -1;
    int n = arr.size() / 2 + 1;
    int dp[102][101][2];
    for (int j = 0; j < n; j++) {
        dp[1][j][0] = stoi(arr[2 * j]);
        dp[1][j][1] = stoi(arr[2 * j]);
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j][0] = -1e9;
            dp[i][j][1] = 1e9;
            for (int k = 1; k <i; k++) {
                if (j + k  >= n ) {
                    break;
                }
                int mx = dp[k][j][0];
                mx += (arr[2 * (j + k) - 1] == "-") ? -dp[i-k][j+k][1] : dp[i-k][j+k][0];
                int mn = dp[k][j][1];
                mn += (arr[2 * (j + k) - 1] == "-") ? -dp[i-k][j+k][0] : dp[i-k][j+k][1];
                dp[i][j][0] = max(dp[i][j][0], mx);
                dp[i][j][1] = min(dp[i][j][1], mn);
            }
            if (i == n && j == 0) {
                break;
            }

        }
    }
    return dp[n][0][0];
}
int main() {
    vector<string> arr = { "1", "-", "3", "+", "5", "-", "8" };
    cout<< solution(arr);

}