
/*이 문제는 일반적인 동적 계획법 문제와는 다소 특이한 형태를 가진다.
마지막 집을 기준으로 동적 계획을 수행하는 것이 아니라, 
첫 번째 집을 터는 경우와 터지지 않는 경우로 나누어 각각 동적 계획법을 적용한 뒤, 두 경우에서 얻을 수 있는 최대값 중 더 큰 값을 정답으로 선택하는 문제이다.
*/
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;
int solution(vector<int> money) {
    int answer = 0;
    int n = money.size();
    
    vector<int> dp1(n -1);

    dp1[0] = 0;
    dp1[1] = money[1];
    for (int i = 2; i < n - 1; i++) {
        dp1[i] = max(dp1[i - 2] + money[i], dp1[i - 1]);
    }

    vector<int> dp2(n);
    dp2[0] = 0;
    dp2[1] = money[0];
    for (int i = 2; i < n ; i++) {
        dp2[i] = max(dp2[i - 2] + money[i-1], dp2[i - 1]);
    }

  
    return max(money[n-1]+dp1[n-3],dp2[n-1]);
}
int main() {
    vector<int> v = {
    1,7,2,4
    
    };

    cout<<solution(v);
    

}