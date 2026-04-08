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
괜히 풀어보겠다고 한거같다. 막상 힘들게 풀고 나니깐 시간초과가 났다. 왜냐하면 승객마다 bfs를 호출하였기 때문이다. 승객은 최댓값은 400명이고 승객을 모두 
태울 때까지 연산을 한단고 생각하면 8000000번 bfs가 나타난다. 따라서 승객을 태우기 위해 가능한 승객을 한꺼번에 거리를 계산한다음 문제기준으로 가장 가까운 승객을 태워야한다.
*/
int mp[20][20];
vector<pair<int, int>> customer,destination;
int tx, ty;
int dt[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int n, m;
long long f;
int cusvis[400];
bool compare(vector<int>a, vector<int>b) {
	if (a[2] == b[2]) {
		if (a[0] == b[0]) {
			return a[1] < b[1];
		}
		return a[0] < b[0];
	}
	return a[2] < b[2];
}
vector<int> bfs(int startx, int starty, int desx, int desy,int num) {
	int visited[20][20];
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			visited[i][j] = 0;
		}
	}
	queue<vector<int>> que;
	que.push({ startx,starty,0 });
	visited[startx][starty] = 1;
	while (!que.empty()) {
		vector<int>cur = que.front();
		que.pop();
		int curx = cur[0],cury=cur[1],d=cur[2];
		if (curx == desx && cury == desy) {
			return { curx,cury,d,num };
		}
		for (int i = 0; i < 4; i++) {
			int nx = curx + dt[i][0];
			int ny = cury + dt[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (mp[nx][ny] != -1&&visited[nx][ny]==0) {
					que.push({ nx,ny,d + 1 });
					visited[nx][ny] = 1;
				}
			}
		}
	}
	int infi = 1e9;
	return {-1,-1,infi,-1};
}
int findNearCustomer() {
	int visited[20][20];
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			visited[i][j] = 0;
		}
	}
	vector<vector<int>>nearcustomer;
	queue<vector<int>> que;
	que.push({ tx,ty,0 });
	visited[tx][ty] = 1;
	int sm = 1e9;
	while (!que.empty()) {
		vector<int>cur = que.front();
		que.pop();
		int curx = cur[0], cury = cur[1], d = cur[2];
		if (mp[curx][cury]>0) {
			if (d <= sm) {
				sm = d;
				nearcustomer.push_back({ curx,cury,d,mp[curx][cury] });

			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = curx + dt[i][0];
			int ny = cury + dt[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (mp[nx][ny] != -1 && visited[nx][ny] == 0) {
					que.push({ nx,ny,d + 1 });
					visited[nx][ny] = 1;
				}
			}
		}
	}
	if (nearcustomer.size() == 0) {
		return -1 ;
	}
	sort(nearcustomer.begin(), nearcustomer.end(), compare);
	tx = nearcustomer[0][0], ty = nearcustomer[0][1];
	f -= nearcustomer[0][2];
	if (f < 0) {
		return -1;
	}
	return nearcustomer[0][3]-1;
}
int main() {

	cin >> n >> m >> f;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
			if (mp[i][j]) {
				mp[i][j] = -1;
			}
		}
	}
	cin >> tx >> ty;
	tx--;
	ty--;
	for (int i = 1; i <= m; i++)
	{
		int sx, sy,dx,dy;
		cin >> sx>> sy >> dx >> dy;
		mp[sx - 1][sy - 1] = i;
		customer.push_back({ sx-1,sy-1 });
		destination.push_back({ dx-1,dy-1 });
	}

	while (1) {
		vector<vector<int>> arr;
		
		int ncustom=findNearCustomer();
		if (ncustom == -1) {
			break;
		}
		vector<int>dis = bfs(tx, ty, destination[ncustom].first, destination[ncustom].second,ncustom);
		f -= dis[2];
		tx = dis[0], ty = dis[1];
		if (f < 0) {
			break;
		}
		cusvis[ncustom] = 1;
		f += dis[2] * 2;
		mp[customer[ncustom].first][customer[ncustom].second] = 0;
		int sf = 1;
		for (int i = 0; i < m; i++) {
			if (cusvis[i] == 0) {
				sf = 0;
				break;
			}
		}
		if (sf == 1) {
			break;
		}
	}
	int sf = 1;
	for (int i = 0; i < m; i++) {
		if (cusvis[i] == 0) {
			sf = 0;
			break;
		}
	}
	if (sf == 0) {
		cout << -1;
	}
	else {
		cout << f;
	}
}


	

