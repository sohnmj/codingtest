#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int sqr(int x) {
	return x * x;
}
int sqrdist(int a, int b, int c, int d) {
	return sqr(a - c) + sqr(b - d);
}
int enclose(int parent, int child, int n, int** castle) {
	int dist = sqrdist(castle[parent][0], castle[parent][1], castle[child][0], castle[child][1]);
	int rdist = sqr(castle[parent][2] - castle[child][2]);
	return (rdist > dist and castle[parent][2] > castle[child][2]);
}
int ischild(int parent, int child, int n,int** castle) {
	if (enclose(parent, child, n, castle) == 0) {
		return false;
	}
	for (int i = 0; i < n; i++) {
		if (i == parent or i == child) continue;
		
		if (enclose(parent, i, n, castle) == false or enclose(i, child, n, castle) == false) {

		}
		else {
			return false;
		}
	}
	return true;


	
}
int maxi;
int height(int root,vector<int>*tree,int*Max) {
	if (tree[root].size()==0) return 0;
	
	vector<int>arr;
	for (auto i : tree[root]) {
		int a = height(i, tree,Max) + 1;
		arr.push_back(a);
		
	}
	sort(arr.begin(), arr.end());
	if (arr.size() >= 2) {
		*Max = max(*Max, arr[arr.size() - 2] + arr[arr.size() - 1]);
	}
	return arr.back();
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int** castle=new int*[n];
		vector<int>* arr = new vector<int>[n];
		for (int j = 0; j < n; j++) {
			castle[j] = new int[3];
		}
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 3; k++) {
				cin >> castle[j][k];
			}

		}
		

	
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				
				if (ischild(j, k, n, castle) == true) {
					arr[j].push_back(k);
				}
			}


		}
		int Max;
		cout << height(0,arr,&Max);
		cout << Max;
		
	}
}