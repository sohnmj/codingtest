/*10진수에서 k진수 변환은 k로 계속 나눈 나머지의 조합으로 변환할 수 있다.그리고 stoll도 존재한다는 사실
*/
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
bool isPrime(long long  num) {
    if (num == 1) {
        return false;
    }
    long long sqr = sqrt(num);
    for (long long i = 2;i <= sqr;i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
int solution(int n, int k) {
    int answer = 0;
    vector<char>str;
    while (n / k != 0) {
        str.push_back(n % k + 48);
        n /= k;
    }
    if (n > 0) {
        str.push_back(n + 48);
    }
    for (int i = str.size() - 1;i >= 0;i--) {
        if (str[i] != '0') {
            string s = "";
            while (str[i] != '0' && i >= 0) {
                s.push_back(str[i]);
                i--;
            }
            long long num = stol(s);
            bool jin = isPrime(num);
            if (jin) answer++;
        }
    }

    return answer;
}
int main() {
    vector<vector<int>>users = { {40, 10000},{25, 10000} };
    vector<int> plans = {
0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1
    };

    vector<int>ans=solution(9,plans);
    for (int i : ans) {
        cout << i <<" ";
    }
}