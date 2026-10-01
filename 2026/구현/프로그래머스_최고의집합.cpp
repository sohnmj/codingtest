/*
그냥 뭔가 이거일 거 같아서 풀었더니 진짜 맞았던 운좋은 문제 정해진 합에서 n개의 원소의 값들의 곱의 최댓 값은 균등하게 퍼진 경우이다.
 */
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include<set>
#include<deque>
#include<cmath>
#include<queue>
typedef long long ll;
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int val = s / n;
    int rest = s % n;

    for (int i = 0;i < n;i++) {
        if (i >= n - rest) {
            answer.push_back(val + 1);
        }
        answer.push_back(val);
    }
    return answer;
}