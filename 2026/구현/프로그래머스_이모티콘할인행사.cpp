//이번에는 완전탐색 문제였다. 10, 20 ,30, 40의 4가지 선택지밖에 없기 때문에 이모티콘 마다 완전탐색을 하면된다.
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include<cmath>
#include<queue>
#include <unordered_map>
using namespace std;
int discounts[4] = { 10,20,30,40 };
vector<int>best(2, 0);
vector<int> find_best(vector<vector<int>>& users, vector<int>& emoticons, vector<int>& emoticons_discount) {
    vector<int>result(2, 0);
    for (auto user : users) {
        int limit = user[1];
        int want_dis = user[0];
        int usum = 0;

        for (int i = 0;i < emoticons.size();i++) {
            int discount = emoticons_discount[i];
            int price = emoticons[i];
            if (want_dis <= discount) {
                usum += price * (100-discount) / 100;
            }
        }
        if (limit <= usum) {
            usum = 0;
            result[0]++;
        }
        result[1] += usum;
    }
    return result;
}
void dfs(vector<vector<int>>& users, vector<int>& emoticons, vector<int>& emoticons_discount, int d) {
    if (d == emoticons.size()) {
        vector<int>result=find_best(users, emoticons, emoticons_discount);
        if (best[0] < result[0]) {
            best = result;
        }
        else if (best[0] == result[0]) {
            if (best[1] < result[1]) {
                best = result;
            }
        }
    }
    else{
        for (int i = 0;i < 4;i++) {
            emoticons_discount[d] = discounts[i];
            dfs(users, emoticons, emoticons_discount, d + 1);
        }
    }
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    vector<int>emticons_discount(emoticons.size(), 0);
    dfs(users, emoticons, emticons_discount, 0);
    return best;
}
int main() {
    vector<vector<int>>users = { {40, 10000},{25, 10000} };
    vector<int> plans = {
7000, 9000
    };


    solution(users,plans);
    cout << "안영하";
}
