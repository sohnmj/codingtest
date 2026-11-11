/*
[로직] 합승 지점 i를 전부 시도: s→i + i→a + i→b 최솟값. 모든 쌍 거리는 n≤200이라 플로이드(k 바깥 루프)로 충분
[문법] -1을 "도달 불가"로 쓰면 min이 -1을 골라 버림 → 갱신·비교 전에 -1인지 먼저 continue로 거를 것
[실수] -1 체크 조건에 dp[s][i]를 두 번 쓰고 dp[i][a]를 빠뜨림. 양방향 그래프라 우연히 통과했으니 조건 세 개를 하나씩 대조할 것
[엣지] dp[i][i]=0이 있어야 i=s(합승 안 함), i=a(a까지 같이 감) 경우가 계산됨. 다익스트라 풀이는 s,a,b에서 3번 돌리면 됨
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    for(auto fare:fares){
        int u=fare[0];
        int v= fare[1];
        int f=fare[2];
        dp[u][v]=f;
        dp[v][u]=f;
    }
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dp[i][k]==-1||dp[k][j]==-1) continue;
                dp[i][j]=(dp[i][j]==-1)?dp[i][k]+dp[k][j]:min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    int min_fare=dp[s][a]+dp[s][b];
    for(int i=1;i<=n;i++){
        if(dp[s][i]==-1||dp[i][a]==-1||dp[i][b]==-1)  continue;
        int withfare=dp[s][i]+dp[i][a]+dp[i][b];
        min_fare=min(withfare,min_fare);
    }
    return min_fare;
}