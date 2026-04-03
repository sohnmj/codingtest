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
설계부터 시작한 풀이였다. 무슨 자료구조를 쓸지 부터 정하니깐 술술 풀렸다. 처음으로 지피티 도움을 안받고 풀었던 것 같다.
*/

vector<vector<int>>tblock;
int mp[2][10][4];

vector<vector<pair<int, int>>>shapeall[2] = {
	{{ {0,0} }, { {0,0},{1,0} }, { {0,0},{0,1} } },
	{{{0,0}}, {{0,0},{0,1}}, {{0,0},{1,0}}}
 };

int n;
void drop(int x, int y, int shape,int bg) {
	if (bg == 0) {
		int temp = x;
		x = y;
		y = temp;
	}
	vector<vector<pair<int, int>>>shapec = shapeall[bg];
	for (int i = 0; i < shapec[shape].size(); i++) {
		int bx = x + shapec[shape][i].first;
		int by = y + shapec[shape][i].second;
		mp[bg][bx][by] = 0;
	}
	while (1) {
		int pos = 1;
		for (int i = 0; i < shapec[shape].size(); i++) {
			int bx = x+1 + shapec[shape][i].first;
			int by = y + shapec[shape][i].second;
			if (bx >= 10 || mp[bg][bx][by] == 1) {
				pos = 0;
				break;
			}
		}
		if (pos) {
			x++;
		}
		else {
			break;
		}
	}
	for (int i = 0; i < shapec[shape].size(); i++) {
		int bx = x + shapec[shape][i].first;
		int by = y + shapec[shape][i].second;
		mp[bg][bx][by] = 1;
	}
}
void down(int row, int bg) {
	for (int i = row-1; i >=4; i--) {
		for (int j = 0; j < 4; j++) {
			mp[bg][i + 1][j] = mp[bg][i][j];
			mp[bg][i][j] = 0;
		}
	}
}
int getscore(int bg) {
	int score = 0;
	for (int i = 4; i < 10; i++) {
		int sflag = 1;
		for (int j = 0; j < 4; j++) {
			if (mp[bg][i][j] == 0) {
				sflag = 0;
				break;
			}
		}
		if (sflag) {
			score++;
			down(i,bg);
		}
	}
	return score;
}
void eliminate(int bg) {
	for (int i = 4; i < 6; i++) {
		int eflag = 0;
		for (int j=0; j < 4; j++) {
			if (mp[bg][i][j] == 1) {
				eflag = 1;
				break;
			}
		}
		if (eflag) {
			down(9, bg);
		}
	}
}
int main() {
	cin >> n;
	int score = 0;
	for (int i = 1; i <= n; i++) {
		int time, x, y;
		cin >> time >> x >> y;
		tblock.push_back({ x,y,time });
	}
	for (auto i : tblock) {
		int x = i[0];
		int y = i[1];
		int t = i[2]-1;
		drop(x, y, t, 0);
		drop(x, y, t, 1);
		score += getscore(0);
		score += getscore(1);
		eliminate(0);
		eliminate(1);
	}
	cout << score<<'\n';
	int cnt = 0;
	for (int bg = 0; bg < 2; bg++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 4; j++) {
				if (mp[bg][i][j]) {
					cnt++;
				}
			}
		}
	}
	cout << cnt;
}


	

