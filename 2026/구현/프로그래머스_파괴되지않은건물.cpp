/*
[로직] 2차원 차분 배열: 직사각형 (r1,c1)~(r2,c2)에 d를 더할 때 네 꼭짓점에만 +d, -d, -d, +d를 찍고, 가로 누적합 후 세로 누적합으로 복원 → 스킬 1개당 O(1)
[문법] change를 (n+1)x(m+1)로 만들어 r2+1, c2+1 인덱스가 범위를 넘지 않게 함. t==1(공격)이면 d*=-1로 부호만 바꿔 같은 식 재사용
[엣지] 매번 직사각형을 직접 칠하면 O(K*N*M)로 시간 초과 → 차분 배열이면 O(K+N*M). 누적합은 n x m까지만 돌려도 됨(n행, m열은 상쇄용 칸)
*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n=board.size();
    int m=board[0].size();
    vector<vector<int>>change(board.size()+1,vector<int>(board[0].size()+1,0));
    for(auto sk:skill){
        int t=sk[0],r1=sk[1],c1=sk[2],r2=sk[3],c2=sk[4],d=sk[5];
        if(t==1){
            d*=-1;
        }
        change[r1][c1]+=d;
        change[r1][c2+1]-=d;
        change[r2+1][c1]-=d;
        change[r2+1][c2+1]+=d;
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            change[i][j]+=change[i][j-1];
        }
    }
    for(int j=0;j<m;j++){
        for(int i=1;i<n;i++){
            change[i][j]+=change[i-1][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            board[i][j]+=change[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]>0){
                answer++;
            }
        }
    }
    return answer;
}