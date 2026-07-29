/*이문제는 그리디와 dfs가 섞여 있어서 헷갈렸던 문제였던 것 같다. 라이언이 최대 차이를 만들기 위해 특정 점수를 얻는 것은 특정 점수에 아파치의 화살 수보다 1더해서 쏘면된다.
하지만 어떤 특정 점수를 조합하는지에 따라 점수 차이가 달라지 기때문에 이는 dfs를 활용하여 해당 경우의 수를 구하면 된다.
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
vector<int>mx(11,0);
int maxdif = 0;
vector<int>required;
int num;
bool minMax(vector<int>& cur) {
    for (int i = 10;i >= 0;i--) {
        if (mx[i] || cur[i]) {
            if (mx[i] < cur[i]) {
                return true;
            }
            else if (mx[i] == cur[i]) {

            }
            else {
                return false;
            }
        }
    }
}
int getAp(vector<int>& info, vector<int>& cur) {
    int ap = 0;
    for (int i = 10;i >= 0;i--) {
        if (info[i]) {
            if (info[i] >= cur[i]) {
                ap += 10 - i;
            }
        }
    }
    return ap;
}
void dfs(int cnt,int score,int idx, vector<int>& cur, vector<int>& info) {

    for (int i = idx;i < 11;i++) {
        int require = required[i];
        if (cnt + require <= num) {
            cur[i] = require;
            dfs(cnt + require, score + 10 - i, i+1, cur,info);
            cur[i] = 0;
        }
    }
    int ap = getAp(info, cur);
    if (maxdif <= score-ap) {
        if (cnt < num) {
            cur[10] = num - cnt;
        }
        
        if (maxdif < score-ap) {
            mx = cur;
            maxdif = score - ap;
        }
        else if (maxdif==score-ap && minMax(cur)) {
            mx = cur;
            maxdif = score - ap;
        }
        if (cnt < num) {
            cur[10] = 0;
        }
    }
    

}
vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    num = n;
    for (int i = 0;i < 11;i++) {
        required.push_back(info[i] + 1);
    }
    vector<int>cur(11, 0);
    dfs(0, 0, 0, cur,info);
    if (maxdif > 0) {
        return mx;
    }
    else {
        return { -1 };
    }

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