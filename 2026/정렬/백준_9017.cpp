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

bool compare(vector<int>a, vector<int>b) {
	if (a[0] == b[0]) {
		return a[1] < b[1];
	}
	return a[0] < b[0];
}

int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		vector<int>teams[201];
		vector<vector<int>>trank;
		
		int n;
		int norank[1001];
		cin >> n;
		int num;
		for (int i = 1; i <= n; i++) {
			cin >> num;
			teams[num].push_back(i);
			norank[i] = 0;
		}
		for (int i = 1; i < 201; i++) {
			int sz = teams[i].size();
			if (sz > 0 && sz < 6) {
				for (auto team : teams[i]) {
					norank[team] = 1;
				}
			}
		}
		for (int i = 2; i <= n; i++) {
			norank[i] += norank[i - 1];
		}
		for (int i = 1; i < 201; i++) {
			if (teams[i].size() == 6) {
				int sum = 0;
				for (int j = 0; j < 4;j++ ) {
					int score= teams[i][j];
					score -= norank[score];
					sum += score;
				}
				trank.push_back({ sum,teams[i][4],i });
			}
		}
		sort(trank.begin(), trank.end(), compare);
		cout << trank[0][2]<<'\n';
		
	}
	
}


	

