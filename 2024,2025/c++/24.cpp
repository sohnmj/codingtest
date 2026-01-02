#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int>arr;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		sort(arr.begin(), arr.end(), greater<int>());
		int sm1 = arr.back();
		arr.pop_back();
		int sm2 = arr.back();
		arr.pop_back();
		sum += sm1 + sm2;
		arr.push_back(sm1 + sm2);
	}
	
	
	cout << sum;
}