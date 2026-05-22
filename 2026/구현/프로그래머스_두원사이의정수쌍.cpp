/*진짜 어렵게도 푼다ㅠㅠ cmath 라이브러리 함수에 더욱 친숙해지자 floor, ceil, sqrt 그리고 숫자 범위 int 초과하는지 항상 생각하기*/
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include<cmath>

using namespace std;

int maxd(int r) {
    int mx = 0;
    for (int i = r / 2; i < r; i++) {
        if ((long long)r * r > (long long )i * i*2) {
            mx = i;
        }
        else {
            break;
        }
    }
    return mx;
}

long long countdot(int r1, int r2) {
    int d1 = maxd(r1);
    int d2 = maxd(r2);
    long long dot = 0;

    for (long long i = d2; i > 0; i--) {

        long long dot2 = floor(sqrt((long long)r2*r2-i*i));
        long long dot1 = i+1;
        if (i < r1) {
            long long dot11 = ceil(sqrt((long long)r1 * r1 - i * i));
            dot1 = max(dot1, dot11);
        }
        if (dot2 >= dot1) {
            dot += dot2 - dot1+1;
        }
    }

    dot *= 8;
    dot = dot + (d2 - d1) * 4 + (r2 - r1) * 4 + 4;
    return dot;
}

long long solution(int r1, int r2) {
    long long answer = 0;
    answer = countdot(r1, r2);
    return answer;
}

int main() {
    vector<vector<int>> targets = {
        {4, 5},
        {4, 8},
        {10, 14},
        {11, 13},
        {5, 12},
        {3, 7},
        {1, 4}
    };

    vector<vector<int>> b = {
        {1, 2, 1, 2},
        {2, 1, 2, 1}
    };

    cout << solution(2, 3);
}