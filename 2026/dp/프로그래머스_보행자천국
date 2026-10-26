/*
 * [보행자 천국] 정리 노트
 *
 * ───────── 내가 했던 오해 ─────────
 *
 * 1. "BFS/DFS는 모든 경우를 탐색한다" → ❌
 *    - visited를 한 번 체크하는 보통 BFS/DFS는 "모든 정점(칸)"을 한 번씩 방문할 뿐이다.
 *      같은 칸에 다른 경로로 와도 처음 하나만 남기고 버린다.
 *      → 최단 거리, 도달 여부에는 맞지만 "경로의 개수"는 틀린다.
 *    - "모든 경로"를 보는 건 visited를 돌아올 때 풀어주는 백트래킹 DFS다.
 *      → 맞지만 경로 수만큼 걸려서 격자가 크면 시간 초과.
 *    - 격자도 그래프다 (칸 = 정점, 상하좌우 = 간선).
 *
 * 2. 경우의 수는 DP로 센다
 *    - 같은 상태에 도착한 경로들을 "개수"로 합친다: cnt[다음] += cnt[현재]
 *    - 상태를 (칸, 들어온 방향)으로 잡아야 한다. 2인 칸은 직진만 되니까 방향을 기억해야 함.
 *      (경주로 건설, Rainbow Path와 같은 "상태 추가" 아이디어)
 *
 * 3. DFS + 메모이제이션도 DP다 (top-down)
 *    - dfs(y, x, dir) = "여기서 도착점까지 남은 경로 수"는 지금까지 온 길과 무관
 *      → 한 번 계산하면 cache에 저장하고 재사용.
 *    - cache는 -1로 초기화 (0은 "경로 0개"라는 진짜 답일 수 있어서 구분 불가).
 *    - 백트래킹이 시간 초과면: 결과가 "지금까지 온 경로"와 무관한지 보고, 무관하면 cache 붙이기.
*/


#include <vector>
#include<bits/stdc++.h>

using namespace std;

int MOD = 20170805;
int dr[2][2]={{1,0},{0,1}};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(2)));
    dp[0][0][0]=1,dp[0][0][1]=0;
    // for(int i=0;i<n;i++){
    //     dp[i][0][1]=0;
    // }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
                if(city_map[i][j]==0){
                    for(int k=0;k<2;k++){
                        int nx=i+dr[k][0], ny=j+dr[k][1];
                        if(nx<0||nx>=m||ny<0||ny>=n) continue;
                        dp[nx][ny][k] = (dp[nx][ny][k] + dp[i][j][0] + dp[i][j][1]) % MOD;
                    }
                }
                else if(city_map[i][j]==2){
                    for(int k=0;k<2;k++){
                        int nx=i+dr[k][0], ny=j+dr[k][1];
                        if(nx<0||nx>=m||ny<0||ny>=n) continue;
                        dp[nx][ny][k]+=dp[i][j][k];
                    }
                }            
        }
    }
    return (dp[m-1][n-1][0] + dp[m-1][n-1][1]) % MOD;
}