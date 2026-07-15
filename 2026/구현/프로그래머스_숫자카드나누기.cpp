//수학적으로 최대공약수를 묻는게 맞았는데 구하는 법을 몰랐다. ㅠ 유클리드 호제법에 대해 알게됨
#include<iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include<cmath>
#include<queue>
#include <unordered_map>
using namespace std;
int gcd(int a, int b) {
    if (a%b == 0) {
        return b;
    }
    return gcd(b, a % b);
}
int notdivide(vector<int>& arr, int gcd) {
    for (auto i : arr) {
        if (i % gcd == 0) {
            return 1;
        }
    }
    return 0;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    sort(arrayA.begin(), arrayA.end());
    int gcdA=arrayA[0];
    sort(arrayB.begin(), arrayB.end());
    int gcdB = arrayB[0];
    for (int i = 0;i < arrayA.size();i++) {
        gcdA = gcd(arrayA[i], gcdA);
    }
    if (notdivide(arrayB, gcdA)) {
        gcdA = 0;
    }
    for (int i = 0;i < arrayB.size();i++) {
        gcdB = gcd(arrayB[i], gcdB);
    }
    if (notdivide(arrayA, gcdB)) {
        gcdB = 0;
    }

    return max(gcdA,gcdB);
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