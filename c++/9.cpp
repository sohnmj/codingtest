#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;
int main() {
	int dpx[4] = {1,0,-1,0};
	int dpy[4] = { 0,1,0,-1};
	int dir = 0;
	vector<pair<int, int>>snake;
	snake.push_back(make_pair(0, 0 ) );
	int map[100][100] = { 0 };
	int n;
	int time = 0;
	int a, b;
	cin >> n;
	cin >> a;
	for (int i = 0; i < a; i++) {
		int x, y;
		cin >> y>> x;
		map[y-1][x-1] = 1;
	}
	cin >> b;
	for (int i = 0; i < b; i++) {
		int t;
		char c;
		cin >> t >> c;
		while(time<t) {
			
			int hx = snake[0].first+dpx[dir];
			int hy = snake[0].second+dpy[dir];
			if (hx < 0 || hx >= n || hy < 0 || hy >= n) {
				cout << time+1;
				exit(0);
			}
			auto it = find(snake.begin(), snake.end(), make_pair(hx,hy));
			if (it != snake.end()) {
				cout << time+1;
				exit(0);
			}
			snake.insert(snake.begin(),  make_pair(hx,hy) );
			if (map[hy][hx]!=1) {
				snake.pop_back();
			}
			else {
				map[hy][hx] = 0;
			}
			time++;
		}
		if (c == 'D') {
			dir = (dir + 1) % 4;	
		}
		else {
			dir=(dir+3)%4;
		}
		
	}
	while(1){

		int hx = snake[0].first + dpx[dir];
		int hy = snake[0].second + dpy[dir];
		if (hx < 0 || hx >= n || hy < 0 || hy >= n) {
			cout << time+1;
			exit(0);
		}
		auto it = find(snake.begin(), snake.end(), make_pair(hx, hy));
		if (it != snake.end()) {
			cout << time+1;
			exit(0);
		}
		snake.insert(snake.begin(), make_pair(hx, hy));
		if (map[hy][hx] != 1) {
			snake.pop_back();
			
		}
		else {
			map[hy][hx] = 0;
		}
		time++;
	}


}