/* 또 if문을 복잡하게 만드는 바람에 많이 틀리고 말았다. 그리고 Long 을 써야할지 Int를 써야할지 잘 고려하자*/
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include<cmath>
#include<queue>
#include <unordered_map>
#include<set>
#include<iostream>
typedef long long ll;
using namespace std;
bool compare1(pair<ll, ll>& a, pair<ll, ll>& b) {
    return a.second < b.second;
}

vector<string> solution(vector<vector<int>> line) {

    set<pair<int, int>>s;
    int len = line.size();
    for (int i = 0;i < len;i++) {
        for (int j = i + 1;j < len;j++) {
            ll x1 = (ll)line[i][0];
            ll y1 = (ll)line[i][1];
            ll c1 = (ll)line[i][2];
            ll x2 = (ll)line[j][0];
            ll y2 = (ll)line[j][1];
            ll c2 = (ll)line[j][2];
            ll y3;
            ll x3;
            if ((x1 * y2 - x2 * y1) != 0 && (x2 * c1 - x1 * c2) % (x1 * y2 - x2 * y1) == 0&& (y1 * c2 - y2 * c1) % (x1 * y2 - x2 * y1) == 0) {
                y3 = (x2 * c1 - x1 * c2) / (x1 * y2 - x2 * y1);
                x3 = (y1 * c2 - y2 * c1) / (x1 * y2 - x2 * y1);
                s.insert({ y3,x3 });

            }
        }
    }
    vector<pair<ll, ll>>v(s.begin(), s.end());
    sort(v.begin(), v.end());
    ll topy = v.back().first;
    ll miny = v[0].first;
    sort(v.begin(), v.end(), compare1);
    ll topx = v.back().second;
    ll minx = v[0].second;
    ll width = topx - minx + 1;
    ll height = topy - miny + 1;
    string row = "";
    for (ll i = 0;i < width;i++) {
        row += '.';
    }
    vector<string> answer(height, row);
    for (auto i : v) {
        answer[topy - i.first][i.second - minx] = '*';
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