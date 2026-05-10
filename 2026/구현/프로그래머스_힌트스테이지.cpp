#include <string>
#include <vector>
#include<deque>
using namespace std;

//범위 조건 신경쓰자
int bfs_cost(vector<vector<int>> cost, vector<vector<int>> hint) {
    deque<vector<int>>dq;
    int minimun = 1e9;
    //처음 스테이지 (stage,cost,[hint 개수])
    vector<int>first_stage(cost.size() + 2, 0);
    dq.push_back(first_stage);
    while (!dq.empty()) {
        vector<int>cur = dq.front();
        int cur_stage = cur[0];
        int cur_cost = cur[1];

        dq.pop_front();

        cur_cost += cost[cur_stage][cur[cur_stage + 2]];
        if (cur_stage == cost.size() - 1) {
            if (cur_cost < minimun) {
                minimun = cur_cost;
            }
            continue;
        }
        cur[0]++;
        cur[1] = cur_cost;
        dq.push_back(cur);
        cur[1] += hint[cur_stage][0];
        for (int i = 1;i < hint[cur_stage].size();i++) {
            int h = hint[cur_stage][i];
            if (cur[h + 1] == cost.size() - 1) continue;
            cur[h + 1]++;
        }
        dq.push_back(cur);
    }
    return minimun;
}
int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    int answer = 0;
    answer = bfs_cost(cost, hint);
    return answer;
}int main() {
    vector<vector<int>> arr = {
    {0, 0},
    {3, 1},
    {1, 3},
    {2, 4},
    {1, 1},
    {2, 2},
    {2, 3},
    {0, 4}
    };
    vector<int> arr1 = solution(4, 5, 2, 2, arr);
}