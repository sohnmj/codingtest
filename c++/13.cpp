#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int city[50][50];
int visited[13];
int ch;
int minimum=1e9;
vector<pair<int, int>>chickens;
vector<pair<int, int>>houses;
int check();

void dfs(int start,int d, int m) {
	if (d == m) {
		int dist = check();
		if (minimum > dist) {
			minimum = dist;
		}
	}
	else {
		for (int i = start; i < ch; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				dfs(i+1,d + 1, m);
				visited[i] = 0;
			}
		}
	}
}
int check() {
	int result=0;
	for (auto house : houses) {
		int min=1e9;
		for (int i = 0; i < ch;i++) {
			if (visited[i] == 1) {
				int dist = abs(chickens[i].first - house.first) + abs(chickens[i].second - house.second);
				if (min > dist) min = dist;
			}
		}
		result += min;
	}
	return result;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> city[i][j];
			if (city[i][j] == 2) {
				chickens.push_back(make_pair(i, j));
				ch++;
			}
			else if (city[i][j] == 1) {
				houses.push_back(make_pair(i, j));
			}
		}
	}
	dfs(0,0, m);
	cout << minimum;


}