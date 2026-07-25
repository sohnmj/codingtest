/*처음에 BFS로 분기점을 나눠서 구하는 문제인줄 알았으나 BFS로 구현하기 위해서는 두 큐의 상태를 분기점마다 다르게 저장해야되었고 시간 초과역시 에상되었다. 이럴때 초반에 먼저 그리디라고 한번만 생각해보자
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
typedef long long ll;
ll sum;
ll sum1 = 0;
ll sum2 = 0;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;

    deque<int>q1;
    deque<int>q2;
    for (int i : queue1) {
        q1.push_back(i);
        sum1 +=(ll) i;
    }
    for (int i : queue2) {
        sum2 +=(ll) i;
        q2.push_back(i);
    }
    if (sum1 == sum2) {
        return answer;
    }
    sum = sum1 + sum2;
    sum /= 2;
    int len1 = q1.size();
    int len2=q2.size();
    while (sum1 != sum2) {
        if (answer > 2 * (len1 + len2)) {
            break;
        }
        if (sum1 > sum2) {
            int temp = q1.front();
            q2.push_back(temp);
            q1.pop_front();
            sum1 -= (ll)temp;
            sum2 += (ll)temp;
        }
        else {
            int temp = q2.front();
            q1.push_back(temp);
            q2.pop_front();
            sum2 -= (ll)temp;
            sum1 += (ll)temp;
        }
    }
    return answer;
    
}
int main() {
    vector<vector<int>>users = { {40, 10000},{25, 10000} };
    vector<int> plans = {
8, 6, 3, 7, 2, 5, 1, 4
    };

    cout<<solution(plans);
    //cout << solution(3,7);
    //cout << "안영하";
}