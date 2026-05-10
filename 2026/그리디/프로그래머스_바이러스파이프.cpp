#include <string>
#include <vector>
#include<deque>
#include<set>
using namespace std;

vector<pair<int,int>>adj[101];
int maxi = 0;
void count_inf(vector<int>arr,int ifn,int k) {
    set<int>infections;
    infections.insert(ifn);
    for (int i = 0;i < k;i++) {
        int type = arr[i];
        deque<int>dq;
        for (auto ith : infections) {
            dq.push_back(ith);
        }
        while(!dq.empty()){
            int infection = dq.front();
            dq.pop_front();
            for (auto edge : adj[infection]) {
                int des = edge.first;
                int t = edge.second;
                if (t == type) {
                    if (infections.count(des)) continue;
                    infections.insert(des);
                    dq.push_back(des);
                }
            }
        }

    }
    int cnt = infections.size();
    if (cnt > maxi) {
        maxi = cnt;
    }
}
void per_bfs(int d,int k,vector<int>&arr,int ifn) {
    if (d == k) {
        count_inf(arr, ifn,k);
    }
    else {
        for (int i = 1;i < 4;i++)
        {
            arr.push_back(i);
            per_bfs(d + 1, k, arr, ifn);
            arr.pop_back();
        }
    }
}
int solution(int n, int infection, vector<vector<int>> edges, int k) {
    int answer = 0;
    for (auto i : edges){
        int a = i[0],b=i[1],t=i[2];
        adj[a].push_back({ b,t });
        adj[b].push_back({ a,t });
    }
    vector<int>arr;
    per_bfs(0, k, arr,infection);
    return maxi;
}
int main() {
    vector<vector<int>> arr = {
        {1, 2, 1},
        {1, 3, 1},
        {1, 4, 3},
        {1, 5, 2},
        {5, 6, 1},
        {5, 7, 1},
        {2, 8, 3},
        {2, 9, 2},
        {9, 10, 1}
    };
   int arr1 = solution(10, 1, arr,2);
}