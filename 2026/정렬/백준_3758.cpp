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
변수명을 잘못했고 먼저 손풀이 한게 좋았던 것 같다
실수가 너무 많다 줄이자
*/
bool compare(vector<int>a, vector<int>b) {
	if (a[0] == b[0]) {
		if (a[1] == b[1]) {
			return a[2] <b[2];
		}
		return a[1] < b[1];
	}
	return a[0] > b[0];
}

int arr[101][101];

int main() {
	int t;
	cin >> t;
	int n, k, mt, m;
	for (int h = 0; h < t; h++) {
		vector<vector<int>>sr(101,vector<int>(4,0));
		
		cin >> n >> k >> mt >> m;
		for (int i = 1; i <= n; i++) {
			sr[i][3] = i;
			for (int j = 1; j <= k; j++) {
				arr[i][j] = 0;
			}
		}
		for (int i = 0; i < m; i++) {
			int tt, tp, ts;
			cin >> tt >> tp >> ts;
			if (arr[tt][tp] < ts) {
				sr[tt][0] -= arr[tt][tp];
				arr[tt][tp] = ts;
				sr[tt][0] += arr[tt][tp];
				
				
			}
			sr[tt][2] = i;
			sr[tt][1]++;
		}

		sort(sr.begin(), sr.end(), compare);
		int result=0;
		for (auto r : sr) {
			result++;
			if (mt == r[3]) {
				break;
			}
		}
		cout << result << '\n';
	}

}