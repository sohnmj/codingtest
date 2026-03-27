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
처참하게 못풀었다.
1. 설계시간에 더 시간을 쏟아야겠다.
2. 1차원 배열이 더 효과적일 떄가 있다. 데이터 구조 결정할때 신중히
3.핵심적인 로직을 따로 함수로 만들어서 구현하자
4.벡트래킹을 할때 방문 표시가 중요하다.
*/
int sc[33] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40,
	13, 16, 19, 22, 24, 28, 27, 26, 25, 30, 35, 0 };

int blue_move[33]; // 파란색 칸(10, 20, 30)에서 꺾이는 칸


int next_move[33] = {
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10, // 0~9
	11, 12, 13, 14, 15, 16, 17, 18, 19, 20, // 10~19
	32, // 20번(40점) -> 32번(도착)
	22, 23, 29, // 21~23 (10점에서 꺾이는 길)
	25, 29,     // 24~25 (20점에서 꺾이는 길)
	27, 28, 29, // 26~28 (30점에서 꺾이는 길)
	30, 31, 20, // 29~31 (중앙 길 25, 30, 35 -> 40점)
	32          // 32번(도착) -> 32(자기자신)
};

int dices[10];
int player[4][2];
int visited[41];

int mx = 0;
void dfs(int d,int score) {
	if (d == 10) {
		if (mx < score) {
			mx = score;
		}
		return;
	}
	int cnt = dices[d];
	for (int i = 0; i < 4; i++) {
		if (player[i][1] == 0) {
			int lc = player[i][0];
			int nlc = lc;
			if (nlc == 5) {
				nlc = blue_move[nlc];
			}
			else if (nlc == 15) {
				nlc = blue_move[nlc];
			}
			else if (nlc == 10) {
				nlc = blue_move[nlc];
			}
			else {
				nlc = next_move[nlc];
			}
			for (int j = 1; j < cnt; j++) {
				nlc = next_move[nlc];
			}
			if (nlc == 32) {
				player[i][1] = 1;
				player[i][0] = nlc;
				visited[lc] = 0;
				dfs(d + 1, score);
				player[i][1] = 0;
				player[i][0] = lc;
				visited[lc] = 1;
			}
			else if (visited[nlc] == 0) {
				visited[nlc] = 1;
				player[i][0] = nlc;
				visited[lc] = 0;
				dfs(d + 1, score + sc[nlc]);
				visited[nlc] = 0;
				visited[lc] = 1;
				player[i][0] = lc;
			}
		}
		
	}
}
int main() {
	for (int i = 0; i < 10; i++) {
		cin >> dices[i];
	}
	blue_move[5] = 21;
	blue_move[15] = 26;
	blue_move[10] = 24;
	dfs(0, 0);
	cout << mx;
}