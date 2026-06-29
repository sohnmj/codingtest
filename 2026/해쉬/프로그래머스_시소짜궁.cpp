//그냥 자료형의 법위 한계도 생각도 안하고 또 중복 제거 중복에 대한 고려조차 안한 쓰레기 같은 문제 풀이였다.
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include<cmath>
#include<queue>
#include <unordered_map>
using namespace std;
long long solution(vector<int> weights) {
    long long answer = 0;
    unordered_map<int, long long>uw;

    for (int i : weights) {
        uw[i]++;
    }
    for (auto cur : uw) {

        int i = cur.first;
        long long n = cur.second;
        int pairw = i * 2;
        if (uw.count(pairw)) {
            answer += n * uw[pairw];
        }
        if (i % 2 == 0) {
            pairw = i / 2 * 3;
            if (uw.count(pairw)) {
                answer += n * uw[pairw];
            }
        }
        if (i % 3 == 0) {
            pairw = i / 3 * 4;
            if (uw.count(pairw)) {
                answer += n * uw[pairw];
            }
        }
        if (uw[i] >= 2) {
            answer += (((long long)uw[i] * (uw[i] - 1)) / 2);

        }
    }
    return answer;
}
int main() {
    vector<int> plans = {
100,180,360,100,270
    };


    cout << solution(plans);
    cout << "안영하";
}
