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


/*
바이러스들의 위치를 모두 저장한 다음, 조합을 이용해 활성화할 바이러스 그룹을 선택했다.
각 조합마다 BFS를 수행하여 모든 빈 칸이 감염되기까지의 최소 시간을 구하는 방식으로 문제를 해결할 수 있다.

하지만 이 방식은 조합의 개수만큼 BFS를 수행해야 하기 때문에 시간이 많이 소요된다는 단점이 있다.

이를 개선하기 위해 각 바이러스에서 모든 칸까지의 전염 시간을 BFS로 미리 계산해 저장해 두었다.
이후 조합을 만들 때마다 BFS를 다시 수행하는 대신, 선택된 바이러스들이 해당 칸에 도달하는 시간 중 최솟값을 계산하여 전체 감염 시간을 구하는 방식으로 최적화하였다.
*/
int n, m,len;
int mp[50][50];
int num = 0;
vector<pair<int, int>>viruses;
vector<int>av;
int dt[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int mintime = 1e9;
void spread() {
    int time = 0;
    int count = 0;
    int mp1[50][50];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mp1[i][j] = mp[i][j];
    queue<vector<int>>q;
    for (auto i : av) {
        q.push({ viruses[i].first,viruses[i].second,1});
    }
    while (!q.empty()) {
        if (count == num) {
            if (time < mintime) {
                mintime = time;
            }
            return;
        }
        vector<int>cur = q.front();
        q.pop();
        int r = cur[0];
        int c = cur[1];
        int t = cur[2];
        time = t;
        for (int i = 0; i < 4; i++) {
            int nr = r + dt[i][0];
            int nc = c + dt[i][1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                if (mp1[nr][nc] == 0||mp1[nr][nc]==2) {
                    if(mp1[nr][nc]==0) count++;
                    q.push({ nr,nc,t+1 });
                    mp1[nr][nc] = 3;
                }
            }
        }
    }
   
    if (count == num) {
        if (time < mintime) {
            mintime = time;
        }
    }

}
void comb(int st, int d, int l) {
    if (d == l) {
        spread();
        //for (auto i : av) {
        //    cout << i << endl;
        //}
        //cout << endl;
    }
    else {
        for (int i = st; i < len; i++) {
            av.push_back(i);
            mp[viruses[i].first][viruses[i].second] = 3;
            comb(i + 1, d + 1, l);
            mp[viruses[i].first][viruses[i].second] = 2;
            av.pop_back();
        }
    }
}
int main() {

    cin >> n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 2) {
                viruses.push_back({ i,j });
            }
            else if (mp[i][j] == 0) {
                num++;
            }
        }
    }
    len = viruses.size();
    comb(0, 0, m);

    if (mintime == 1e9) cout << -1;
    else cout << mintime;
}