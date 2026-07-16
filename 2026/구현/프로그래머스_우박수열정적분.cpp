//너무 단순하게 풀었다.누적합으로 구한 다음에 만약 [a,b]를 구하려면 b까지의 합에서 a까지의 합을 빼서 구하면 더 계산량을 줄일 수 있다.
#include<iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include<cmath>
#include<queue>
#include <unordered_map>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<double>arr;
    arr.push_back(k);
    while (k != 1) {
        if (k % 2 == 0) {
            k /= 2;
        }
        else {
            k = k * 3 + 1;
        }
        arr.push_back((double)k);
    }
    for (vector<int> i : ranges) {
        int st = i[0];
        int ls = arr.size()-1 + i[1];

        if (st > ls) {
            answer.push_back(-1.0);
            continue;
        }
        double sum = 0;
        for (int j = st + 1;j <= ls;j++) {
            sum += ((arr[j - 1] + arr[j])) / 2.0;
        }
        answer.push_back(sum);
    }
    return answer;
}


int main() {
    vector<vector<int>>users = { {40, 10000},{25, 10000} };
    vector<int> plans = {
7000, 9000
    };

    cout << 4 % 1;
    //cout << solution(3,7);
    //cout << "안영하";
}