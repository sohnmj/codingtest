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


/*
이 문제는 조합 문제였습니다. 단순히 DFS로 모든 경우를 탐색하면
순열에 가까운 방식으로 원소를 생성하게 되므로 중복이 발생하고,
결과적으로 시간초과가 발생합니다.

중복을 제거하기 위해, 조합을 만들 때는 항상 선택할 원소의 인덱스를
오름차순으로 제한했습니다. 이렇게 하면 (0,1)과 (1,0) 같은
중복 조합이 생성되지 않습니다.
*/
int vis[20] = { 0, };
int dif = 1e9;

vector<vector<int>>adj(20, vector<int>(20));
void caculate_dif(int n) {
    vector<int>arr1;
    vector<int>arr;
    for (int i = 0; i <n; i++) {
        if (vis[i] == 0) arr1.push_back(i);
        else arr.push_back(i);
    }
    int sums = 0;
    for (int i : arr) {
        for (int j : arr) {
            sums += adj[i][j];
        }
    }
    int suml = 0;
    for (int i : arr1) {
        for (int j : arr1) {
            suml += adj[i][j];
        }
    }
    int dif2 = abs(sums - suml);
    if (dif > dif2) {
        dif = dif2;
    }
}
void dfs(int n,int d,int st) {
    if (d == n / 2) {
        caculate_dif(n);
    }
    for (int i = st; i < n; i++) {
        
        if (vis[i] == 0) {            
            vis[i] = 1;
            dfs(n,d+1,i+1);
            vis[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    dfs(n,0,0);
    cout << dif;
    
    
    
}