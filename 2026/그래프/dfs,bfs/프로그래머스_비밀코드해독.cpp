
/*
처음에 조금 어렵게 생각했다가 배열의 크기가 5개밖에 없다는 사실을 깨닫고 순서가 정렬된 조합의 모든 경우를 조건에 맞는지 확인하였다.

*/
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include<queue>
using namespace std;
int answer;
vector<vector<int>> query;
vector<int> answers;
void proper_ans(vector<int>ans_arr) {
    int len = query.size();
    int ans_len = query[0].size();
    for (int i = 0;i < len;i++) {
        int eq_cnt = 0;
        int q_idx = 0;
        for (int j = 0;j < ans_len;j++) {
            while (q_idx<ans_len&&ans_arr[j] > query[i][q_idx]) {
                q_idx++;
            }
            if (q_idx == ans_len) {
                break;
            }
            if (q_idx >= 0 && ans_arr[j] == query[i][q_idx ]) {
                eq_cnt++;
            }
        }
        if (eq_cnt != answers[i]) {
            return;
        }
    }
    for (int i = 0;i < ans_len;i++) {
        cout << ans_arr[i];
    }
    cout << endl;
    answer++;
}
void dfs_ans(vector<int>&arr,int n,int pre,int len) {
    if (arr.size() == len) {
        proper_ans(arr);
    }
    else {
        for (int i = pre+1;i <= n;i++) {
            arr.push_back(i);
            dfs_ans(arr, n, i, len);
            arr.pop_back();
        }
    }
}
int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int len = q.size();
    int ans_len = q[0].size();
    query = q;
    answers = ans;
    vector<int>arr;
    dfs_ans(arr, n, -1, ans_len);
    return answer;
}
int main() {
    vector<vector<int>> v = {{ 2, 3, 9, 12, 13 },
    { 1, 4, 6, 7, 9 },
    { 1, 2, 8, 10, 12 },
    { 6, 7, 11, 13, 15 },
    { 1, 4, 10, 11, 14 }
};
    vector<int>v2 = { 2, 1, 3, 0, 1 };
    cout<<solution(15,v,v2);
    

}