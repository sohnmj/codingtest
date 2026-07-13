//int*int를 long long에 넣어도 int가 된다. 그리고 왠만하면 수학적 식으로 풀려고 노력하자
#include<iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include<cmath>
#include<queue>
#include <unordered_map>
using namespace std;


long long solution(int k, int d) {
    long long answer = 0;
    long long maxk = d / k;
    long long y = maxk * k;
    for (long long  i = 0;i <= maxk;i++) {
        long long x = i * k;

        long long limit = (long long )d * d;
        while (1) {
            long long dis = x * x + y * y;
            if (limit < dis) {
                y -= k;
            }
            else {
                break;
            }
        }
        if (y >= 0) {
            answer += y / k + 1;
        }
    }
    return answer;
}



int main() {
    vector<vector<int>>users = { {40, 10000},{25, 10000} };
    vector<int> plans = {
7000, 9000
    };


    cout << solution(3,7);
    cout << "안영하";
}