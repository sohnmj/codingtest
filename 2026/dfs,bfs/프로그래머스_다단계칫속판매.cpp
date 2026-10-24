/*
unmap을 쓰는 문제, 하지만 0원이 상납금이 되면 이걸 바치는 의미가 없으므로 가지치기를 해야될듯 싶다.
*/
#include <bits/stdc++.h>


using namespace std;

void dfs(int idx, int earn, vector<int>& answer, vector<int>& ref) {
    if (idx == answer.size()||earn==0) {
        return;
    }
    int par = ref[idx];
    int to_par = earn / 10;
    answer[idx] += earn - to_par;
    dfs(par, to_par, answer, ref);

}
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size(), 0);
    unordered_map<string, int>mp;
    int i;
    for (i = 0;i < enroll.size();i++) {
        mp[enroll[i]] += i;
    }
    mp["-"] = i;
    vector<int>ref(enroll.size());
    for (int i = 0;i < referral.size();i++) {
        ref[i] = mp[referral[i]];
    }
    for (int i = 0;i < seller.size();i++) {
        int idx = mp[seller[i]];
        int earn = amount[i] * 100;
        dfs(idx, earn, answer, ref);
    }
    return answer;
}