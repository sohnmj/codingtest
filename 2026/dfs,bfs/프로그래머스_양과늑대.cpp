/*
[로직] 방문한 노드들의 미방문 자식은 언제든 다음 후보 → 상태=(양,늑대,후보목록), 후보를 하나씩 골라 재귀(일반 DFS로는 안 됨)
[문법] candidate는 값 복사로 받아 호출마다 독립(&로 받으면 상태 꼬임), 값 삭제는 erase(find(...)) (Java는 remove(Integer.valueOf(u)))
[실수] 비트마스크가 next를 표현한다고 착각 → 실제론 방문집합 mask, next는 mask에서 매번 계산 + visited[mask]로 중복 제거. 다음엔 비트마스크로 풀어볼 것
[엣지] find 실패 시 erase(end())는 UB → 시작 후보를 {0}으로 넣어 u가 항상 후보에 있게 함. s<=w면 즉시 return
*/
#include<bits/stdc++.h>

using namespace std;
int answer = 0;

void rec(int u,int s,int w ,vector<int>candidate,vector<vector<int>>&adj,vector<int> &info){
    if(!info[u]){
        s++;
    }
    else{
        w++;
    }
    if(s<=w){
        return;
    }
    answer=max(answer,s);
    candidate.erase(find(candidate.begin(),candidate.end(),u));
    for(int v:adj[u]){
        candidate.push_back(v);
    }
    for(int cd:candidate){
        rec(cd,s,w,candidate,adj,info);
    }
    
}
int solution(vector<int> info, vector<vector<int>> edges) {
    int n=info.size();
    vector<vector<int>>adj(n);
    for(auto edge:edges){
        int u=edge[0],v=edge[1];
        adj[u].push_back(v);
    }
    rec(0,0,0,{0},adj,info);
    return answer;
}