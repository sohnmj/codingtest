
/*
이진 탐색 문제

*/
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include<queue>
using namespace std;
int min_level;
long long solve_cost(int level, vector<int> diffs, vector<int> times) {
    long long cost = 0;
    for (int i = 0;i < diffs.size();i++) {
        int diff = diffs[i];
        int time_cur = times[i];
        int time_prev = 0;
        if (i != 0) {
            time_prev = times[i - 1];
        }
        if (level >= diff) {
            cost += time_cur;
        }
        else {
            int dif= diff - level;
            cost = cost + dif * (time_cur + time_prev) + time_cur;
        }
    }
    return cost;
}
void bs_level(int last,long long limit, vector<int> diffs, vector<int> times)
{
    int start = 1;
    int mid;
    while (start <= last) {
        mid = (start + last) / 2;
        long long cost = solve_cost(mid, diffs, times);
        if (cost > limit) {
            start = mid + 1;
        }
        else if (cost == limit) {
            min_level = mid;
            break;
        }
        else {
            last = mid - 1;
        }
    }
    
}
int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int max_diff = diffs.max_size();
    bs_level(max_diff, limit, diffs, times);
    answer = min_level;
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