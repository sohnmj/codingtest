/*내가 푼 방식처럼 그냥 무식하게 조합으로 풀어도 되고 각 사람당 bfs를 통해 그냥 거리가 2인거리를 모두 탐색하여 P인 지점을 찾으면 된다.*/
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
vector<int>cur;
bool isSafe(int n, int m, vector<pair<int, int>>& person,vector<string>&place) {
    int nx = person[n].first;
    int ny = person[n].second;
    int mx = person[m].first;
    int my = person[m].second;
    int disx = abs(nx - mx);
    int disy = abs(ny - my);
    int dis =  disx+disy ;
    if (dis > 2) {
        return true;
    }
    else if(dis==2){
        if (disx != 0 && disy != 0) {
            int dx = (nx - mx);
            int dy = (ny - my);
            if (place[nx][ny - dy] == 'X' && place[nx - dx][ny] == 'X') {
                return true;
            }
            return false;
        }
        else {
            int dx = (nx - mx) / 2;
            int dy = (ny - my) / 2;
            if (place[nx][ny - dy] == 'X' || place[nx - dx][ny] == 'X') {
                return true;
            }
            return false;
        }
    }
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (auto place : places) {
        vector<pair<int, int>>person;
        for (int i = 0;i < place.size();i++) {
            for (int j = 0;j < place[0].size();j++) {
                if (place[i][j] == 'P') {
                    person.push_back({i,j});
                }
            }
        }
        bool jin = true;
        for (int i = 0;i < person.size();i++) {
            for (int j = i + 1;j < person.size();j++) {
                if (!isSafe(i, j, person, place)) {
                    jin = false;
                    break;
                }
            }
            if (jin == false) {
                break;
            }
        }
        if (jin) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}
int main() {
    std::vector<std::vector<std::string>> places = {

        {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
        {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
    };

    vector<int>ans=solution(places);
    for (int i : ans) {
        cout << i <<" ";
    }
}