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
#include <iomanip> 
using namespace std;
/*
일단 조건 노가다를 너무 많이 했다. 코드의 길이도 너무 길어졌고 또한 식별하기도 힘들다.
BFS에서 나머지 연산을 이용해서 줄여야 될것 같다. 그리고 음수가 될 수 있을때는 나누는 수를 더하면 된다.
변수의 표현식이 계속 반복되면 새로운 변수에 대입하여 사용해야 보기 편할것같다
*/
int n, m,t;
int cd[51][50];
int visited[51][50];
vector<pair<int, int>> sameall;
void rotateCD(int cdn, int d, int k) {
    if (d == 1) {
        for (int i = 0; i < k; i++) {
            int prev = cd[cdn][0];
            for (int j = 0; j < m-1; j++) {
                int index = (j + 1);
                cd[cdn][j] = cd[cdn][index];
            }
            cd[cdn][m - 1] = prev;
        }
    }
    else {
        for (int i = 0; i < k; i++) {
            int prev = cd[cdn][m-1];
            for (int j = m-1; j >0; j--) {
                int index = (j -1);
                cd[cdn][j] = cd[cdn][index];
            }
            cd[cdn][0] = prev;
        }
    }
}
void bfs(int x,int y){
    int cnt;
    queue<pair<int, int>> que;
    que.push({ x,y });
    visited[x][y] = 1;
    vector<pair<int, int>>same;
    same.push_back({ x,y });
    while (!que.empty()) {
        pair<int,int> cur=que.front();
        que.pop();
        int cdn = cur.first;
        int i = cur.second;
        if (cd[cdn][i] == 0) {
            continue;
        }
        int num = cd[cdn][i];
        int dy[] = { -1, 1 };
        for (int d = 0; d < 2; d++) {
            int ni = (i + dy[d] + m) % m; // 한 줄로 좌우 인덱스 계산 끝!

            if (!visited[cdn][ni] && num == cd[cdn][ni]) {
                visited[cdn][ni] = 1;
                same.push_back({ cdn, ni });
                que.push({ cdn, ni });
            }
        }
        if (cdn > 1) { // 1번 원판보다 커야 위가 있음
            int up_cdn = cdn - 1;
            if (!visited[up_cdn][i] && num == cd[up_cdn][i]) {
                visited[up_cdn][i] = 1;
                same.push_back({ up_cdn, i });
                que.push({ up_cdn, i });
            }
        }

        // 아래쪽 원판 확인 (cdn + 1)
        if (cdn < n) { // n번 원판보다 작아야 아래가 있음
            int down_cdn = cdn + 1;
            if (!visited[down_cdn][i] && num == cd[down_cdn][i]) {
                visited[down_cdn][i] = 1;
                same.push_back({ down_cdn, i });
                que.push({ down_cdn, i });
            }
        }
    }
    if (same.size() > 1) {
        for (auto i : same) {
            sameall.push_back(i);
        }
    }
    
}
void processCD() {
    sameall.clear();
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == 0&&cd[i][j]>0) {
               bfs(i, j);
            }
        }
    }
    if (sameall.size()==0) {
        int sm = 0;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                sm += cd[i][j];
                if (cd[i][j]) 
                    cnt++;
            }
        }
        if (cnt > 0) {
            double mid = (double)sm / cnt;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < m; j++) {
                    if (cd[i][j]) {
                        if (mid > cd[i][j]) cd[i][j]++;
                        else if(mid<cd[i][j]) cd[i][j]--;
                    }
                }
            }
        }
    }
    else {
        for (auto i : sameall) {
            int x = i.first;
            int y = i.second;
            cd[x][y] =0;
        }

    }
}
void rotate(int x, int d, int k) {
    for (int i = 1; i <= n; i++) {
        if (i % x == 0) {
            rotateCD(i, d, k);
        }
    }

    processCD();
  
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cd[i][j];
        }
    }
    for (int i = 0; i < t; i++) {
        int x,d,k;
        cin >> x >> d >> k;
        rotate(x, d, k);
    }
    int cds = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cds += cd[i][j];
        }
    }
    cout << cds;

}