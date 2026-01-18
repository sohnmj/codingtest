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
처음에는 위상 정렬을 생각했지만 누락된 순위 정보가 있기 때문에 별 도움이 안될 것 같아서 그냥 dfs를 이용했다. 
인접 배열은 {A,B}일 때 A->B,A<-B인 총 2개의 인접 배열을 만들었디.
각 선수마다 실력이 더좋은 선수들을 세는 
dfs, 실력이 더 안좋은 선수들을 세는 dfs를 총 2번의 dfs를 통해 순위가 확정되는지 확인하였다.
찾아보니 플로이드 워샬 방식으로도 쉽게 풀 수 있었다.
*/
using namespace std;
int vis[101] = { 0, };

void dfs(int x, vector<int>* adj) {

    for (auto i : adj[x]) {
        if (vis[i] == 0) {
            vis[i] = 1;
            dfs(i, adj);
        }
    }
}
int solution(int n, vector<vector<int>> results) {

    int answer = 0;
    //인접선 세팅
    vector<int>* adj;
    vector<int>* adj1;
    adj = new vector<int>[n + 1];
    adj1 = new vector<int>[n + 1];
    for (auto i : results) {
        adj[i[0]].push_back(i[1]);
        adj1[i[1]].push_back(i[0]);
    }


    for (int i = 1; i <= n; i++) {

        //정방향
        for (int j = 1; j <= 100; j++) {
            vis[j] = 0;
        }
        int m = 0;
        dfs(i, adj);
        for (int j = 1; j <= 100; j++) {
            if (vis[j] == 1) {
                m++;
            }
        }
        //역방향
        for (int j = 1; j <= 100; j++) {
            vis[j] = 0;
        }
        int m1 = 0;
        dfs(i, adj1);
        for (int j = 1; j <= 100; j++) {
            if (vis[j] == 1) {
                m1++;
            }
        }
        if (m + m1 == n - 1) {
            answer++;
        }
    }


    return answer;
}
int main() {
    vector<vector<int>> v = { {4, 3},{4, 2},{3, 2},{1, 2},{2, 5} };
    cout<<solution( 5,v);
}