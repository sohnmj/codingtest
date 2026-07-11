//priority_que는 내림차순이 기본값이다.
#include<iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include<cmath>
#include<queue>
#include <unordered_map>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    int enemy_sum=0;
    //vector<int>army;
    for (int i = 0;i < enemy.size();i++) {
        if (pq.size() < k) {
            pq.push(enemy[i]);
            continue;
        }
        if (pq.top() < enemy[i]) {
            int num = pq.top();
            pq.pop();
            pq.push(enemy[i]);
            if (enemy_sum + num <= n) {
                enemy_sum += num;
            }
            else {
                return i;
            }
        }
        else {
            if (enemy_sum + enemy[i] <= n) {
                enemy_sum += enemy[i];
            }
            else {
                return i;
            }
        }
    }
    return enemy.size();
}

int main() {
    vector<vector<int>>users = { {40, 10000},{25, 10000} };
    vector<int> plans = {
7000, 9000
    };


    cout << solution(10, 3, { 12, 11, 4, 2, 1, 5, 8, 6, 7 });
    cout << "안영하";
}