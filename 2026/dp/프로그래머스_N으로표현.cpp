#include<iostream>
#include <string>
#include <vector>
#include<map>
#include<queue>
#include<stack>
#include<utility>
#include<algorithm>
#include<cmath>
#include<set>

#include <unordered_map>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    set<int> dp[9];


    int at[6] = { 0,1,11,111,1111,11111 };
    //사용 횟수를 가지고 dp연산
    for (int i = 1; i <= 8; i++) {
        if (i <= 5) {
            int num = at[i] * N;
            if (num <= 32000) {
                dp[i].insert(num);
            }
        }
        for (int j = 1; j < i; j++) {

            //i-j 사용횟수로 만들 수 있는 수 (4-operation) j 사용횟수로 만들 수 있는 수= i 사용 횟수로 만들 수 있는 수
            for (int x : dp[j]) {
                for (int y : dp[i - j]) {

                    // +
                    dp[i].insert(x + y);

                    // *
                    dp[i].insert(x * y);

                    // - (순서 상관있음) 
                    dp[i].insert(x - y);
                    dp[i].insert(y - x);

                    // /(순서 상관 있음)
                    if (y != 0) dp[i].insert(x / y);
                    if (x != 0)dp[i].insert(y / x);
                }
            }
        }
        if (dp[i].count(number)) {
            answer = i;
            break;
        }
    }
    return answer;
}
int main() {
    vector<int>arr = { 40, 50, 60 };
    vector<int>arr1 = { 3,5};
    string str = "4177252841";
    int s = solution(5,12);
    cout << s;
}