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
easy
*/

int main() {
	string s;
	cin >> s;
	int l = s.length();
	int visited[500];
	int lcnt = 0;
	for (int i = 0; i < l; i++) {
		if (s[i] == '1') {
			lcnt++;
		}
		visited[i] = 0;
	}
	int ocnt = l - lcnt;
	lcnt /= 2;
	ocnt /= 2;
	for (int i = 0; i < l; i++) {
		if (s[i] == '1' && lcnt > 0) {
			visited[i] = 1;
			lcnt--;
		}
		if (s[l - 1 - i] == '0'&&ocnt>0) {
			visited[l - 1 - i] = 1;
			ocnt--;
		}
	}
	for (int i = 0; i < l; i++) {
		if (visited[i] == 0) {
			cout << s[i];
		}
	}

}