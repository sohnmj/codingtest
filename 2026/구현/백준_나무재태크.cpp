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
구현 문제 우선 순위큐는 인덱스로는 탐색이 불가능하다는 것을 알았고 모든 원소를 탐색하는 과정에서 pop하고 push를 반복하니 시간초과가 생겼다.
그 문제를 해결하기 위해 벡터를 정렬를 한후 사용했다.
*/
int n,m,k;
vector<int> tlc[10][10];
int mp[10][10];
int A[10][10];
int deth[10][10];
int dr[8][2] = {
    {-1, -1},  // 위 왼쪽
    {-1,  0},  // 위
    {-1,  1},  // 위 오른쪽
    { 0, -1},  // 왼쪽
    { 0,  1},  // 오른쪽
    { 1, -1},  // 아래 왼쪽
    { 1,  0},  // 아래
    { 1,  1}   // 아래 오른쪽
};




void growdeth(int x,int y) {
    sort(tlc[x][y].begin(), tlc[x][y].end());
    vector<int>detht;
    for (int i = 0; i < tlc[x][y].size(); ) {
        int tr = tlc[x][y][i];
        if (mp[x][y] >= tr) {
            mp[x][y] -= tr;
            tlc[x][y][i]++;  // 나이 1 증가
            i++; // 다음 나무
        }
        else {
            deth[x][y] += tr / 2;
            tlc[x][y].erase(tlc[x][y].begin() + i); // 안전하게 삭제
            // i 증가 안 함 → erase 후 다음 원소가 현재 i에 들어옴
        }
    }
}

void ss() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) deth[i][j] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tlc[i][j].size() > 0) {
                growdeth(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) mp[i][j] += deth[i][j];

}

void makechild(int x, int y) {
    int nx, ny;
    for (int i = 0; i < 8; i++) {
        nx = x + dr[i][0]; ny = y + dr[i][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            tlc[nx][ny].push_back(1);
        }
    }
}

void child(int x, int y) {


    for(auto tr:tlc[x][y]){
        if (tr / 5 > 0 && tr % 5 == 0) {
            makechild(x,y);
        }
    }
}

void fw() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tlc[i][j].size() > 0) {
                child(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) mp[i][j] += A[i][j];

}
int main() {

    cin >> n>>m>>k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
            mp[i][j] = 5;
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y, age;
        cin >> x >> y >> age;
        tlc[x - 1][y - 1].push_back(age);
    }
    for (int t = 0; t < k; t++) {
        ss();
        fw();
    }
    int ct = 0;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) {
            ct += tlc[i][j].size();
        }
    cout << ct;

}