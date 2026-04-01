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
조금 너무 복잡하게 풀었던 것 같다.
현재풀이: 각 자리마다 주변에 좋아하는 사람의 수의 최댓 값이 자리를 구하고 그 다음 구한 자리가 여러자리면 다시 주변 빈자리의 수가 최댓값인 자리를 구하고 
등등... 그냥 한번 자리마다 순환할떄 종아하는 사람의 수 빈자리의 수 자리의 위치를 구한 다음 sort함수를 돌렸으면 더 편했을 것 같다
*/
int n;
int order[401];
int favorite[401][4];
int mp[20][20];
int dt[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int score;
int countf(int x, int y, int nth) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dt[i][0];
		int ny = y + dt[i][1];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			int nnth = mp[nx][ny];
			if (nnth == 0) {
				continue;
			}
			for (int j = 0; j < 4; j++) {
				if (nnth == favorite[nth][j]) {
					cnt++;
					break;
				}
			}
		}
	}
	return cnt;
}
int countv(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dt[i][0];
		int ny = y + dt[i][1];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (mp[nx][ny] == 0) {
				cnt++;
			}
		}
	}
	return cnt;
}
void addscore(int cnt) {
	int adscore = 1;
	if (cnt > 0) {
		for (int i = 0; i < cnt - 1; i++) {
			adscore *= 10;
		}
		score += adscore;
	}
	
}
void seatdecide(int idx) {
	vector<pair<int, int>>ps[5];
	int nth = order[idx];
	int fm = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mp[i][j] == 0) {
				int cnt = countf(i, j, nth);
				if (cnt >= fm) {
					fm = cnt;
					ps[cnt].push_back({ i,j });
				}
			}
		}
	}
	int rx = ps[fm][0].first, ry = ps[fm][0].second;
	if (ps[fm].size() > 1) {
		int vm = 0;
		for (auto i : ps[fm]) {
			int x = i.first;
			int y = i.second;
			int v = countv(x, y);
			if (vm < v) {
				vm = v;
				rx = x;
				ry = y;
			}
			else if (vm == v) {
				if (rx > x) {
					rx = x;
					ry = y;
				}
				else if (rx == x) {
					if (ry > y) {
						rx = x;
						ry = y;
					}
				}
			}
		}
	}
	mp[rx][ry] = nth;
}
int main() {
	int number;
	cin >> n;
	number = n * n;
	for (int i = 0; i < number; i++) {
		int nth;
		cin >> nth;
		order[i] = nth;
		cin >> favorite[nth][0] >> favorite[nth][1] >> favorite[nth][2] >> favorite[nth][3];
	}
	for (int i = 0; i < number; i++) {
		seatdecide(i);
	}
	//for (int i = 0; i < number; i++) {
	//	for (int j = 0; j < number; j++) {
	//		cout << mp[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int nth = mp[i][j];
			int cnt = countf(i, j, nth);
			addscore(cnt);
		}
	}
	cout << score;
}


	

