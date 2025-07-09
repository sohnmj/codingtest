#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
int ma = 0;
int map[200][200];
vector<pair<int, int>>*birus;
int n, k;
int dpx[4] = {1, 0, -1, 0};
int dpy[4] = {0,1,0,-1};
int Eempty() {
    int is_empty = 1;
    for (int i = 1; i <= k; k++) {
        if (!birus[i].empty()) {
            return 0;
        }
    }
    return is_empty;
}
void bfs(int s) {
    int time = 0;
    while (!Eempty()&&time<s) {
        for (int i = 1; i <= k; i++) {
            int limit = birus[i].size();
            for(int t=0;t<limit;t++) {
                int x = birus[i].back().first;
                int y = birus[i].back().second;
                birus[i].pop_back();
                for (int j = 0; j < 4; j++) {
                    int nx,ny;
                    nx = x + dpx[j];
                    ny = y + dpy[j];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        if (map[nx][ny] == 0) {
                            map[nx][ny] = i;
                            birus[i].insert(birus[i].begin(), make_pair(nx, ny));
                        }
                    }

                }
            }
        }
        time++;
    }
}


int main() {

    cin >> n >> k;
    birus = new vector<pair<int, int>>[k+1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] >0) {
                birus[map[i][j]].push_back(make_pair(i, j));
            }
           
        }
    }
    int s, sx, sy;
    cin >> s >> sx >> sy;
    bfs(s);
  
    cout << map[sx-1][sy-1];



}