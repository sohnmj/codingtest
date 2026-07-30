/* leftgroup과 rightgroup이 같을 경우를 생각을 못했다.
right - left < 10^5 제한 사항에도 이게 있었다. ㅁ문제를 제대로 봐야겠다. 따라서 left와 right를 그냥 for문으로 해도 상관없었다. ㅠ
for (long long i = left; i <= right; i++) {
        long long row = i / n;
        long long col = i % n;

        // r행 c열의 값은 max(r, c) + 1
        answer.push_back(max(row, col) + 1); }*/
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include<cmath>
#include<queue>
#include <unordered_map>
#include<set>
#include<iostream>

using namespace std;
typedef long long ll;
vector<int> solution(int n, long long left, ll right) {
    vector<int> answer;
    ll leftgroup = left / n;
    int leftrest = left % n;
    ll rightgroup = right / n;
    int rightrest = right % n;
    if (leftgroup == rightgroup) {
        for (int j = leftrest + 1;j <= rightrest+1;j++) {
            if (j > leftgroup + 1) {
                answer.push_back(j);
            }
            else {
                answer.push_back(leftgroup + 1);
            }
        }
        return answer;
    }
    for (int j = leftrest + 1;j <= n;j++) {
        if (j > leftgroup + 1) {
            answer.push_back(j);
        }
        else {
            answer.push_back(leftgroup + 1);
        }
    }

    for (int i = leftgroup + 1;i < rightgroup;i++) {
        for (int j = 1;j <= n;j++) {
            if (j > i + 1) {
                answer.push_back(j);
            }
            else {
                answer.push_back(i + 1);
            }
        }
    }
    for (int j = 1;j <= rightrest + 1;j++) {
        if (j > rightgroup + 1) {
            answer.push_back(j);
        }
        else {
            answer.push_back(rightgroup + 1);
        }
    }
    return answer;
}
int main() {
    vector<vector<int>>users = { {40, 10000},{25, 10000} };
    vector<int> plans = {
0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1
    };

    vector<int>ans=solution(4,7,14);
    for (int i : ans) {
        cout << i <<" ";
    }
}