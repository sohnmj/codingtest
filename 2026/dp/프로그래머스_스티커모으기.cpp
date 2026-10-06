/*
dp 문제. 일반적인 dp와 달리 원형 배열이라 첫 번째와 마지막 원소가 인접함
→ 둘을 동시에 쓸 수 없으므로 두 경우로 나눠 선형 dp를 각각 수행
  1) 첫 번째 원소를 사용하지 않는 경우: [1, n-1]
  2) 마지막 원소를 사용하지 않는 경우: [0, n-2]
→ 두 결과 중 최댓값이 정답
실수: dp[1]을 sticker[1]로 둬서 0번 원소를 고려 못 함 → max(s[0], s[1])
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
#include<queue>
typedef long long ll;
using namespace std;


int solution(vector<int> sticker)
{
    int answer = 0;
    int len = sticker.size();
    if (len == 1) {
        return sticker[0];
    }
    else if(len==2) {
        return max(sticker[0], sticker[1]);
    }
    vector<int>dp1(len, 0);
    vector<int>dp2(len, 0);
    dp2[len - 1] = sticker[len - 1];
    dp2[0] = dp2[len - 1];
    dp1[0] = sticker[0];
    dp1[1] = max(sticker[1],dp1[0]);
    for (int i = 2;i < len-1;i++) {
        int mx = sticker[i] + dp1[i - 2];
        if (mx < dp1[i - 1]) {
            mx = dp1[i - 1];
        }
        dp1[i] = mx;
    }
    for (int i = 1;i < len - 2;i++) {
        if (i == 1) {
            dp2[i] = dp2[i - 1] + sticker[i];
        }
        else {
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + sticker[i]);
        }
    }
    return max(dp1[len - 2], dp2[len - 3]);
}