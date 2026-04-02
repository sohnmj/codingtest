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
설계는 간단한 문제였다.
먼저 설계하고 입력을 받기
20개를 끊어서 줄바꿈 출력하는 문제였는데 처음에는 20개씩 나눠서 출력해야된다고 생각했는데 그냥 20 배수 일떄마다 줄바꿈을 해주면 되는 문제였다.
*/
int swn,stun;
int switches[101];
vector<pair<int, int>>stu;
void switchsw (int sx, int n) {
	if (sx == 1) {
		int num = n;
		while (swn >= num) {
			switches[num] = switches[num] ? 0 : 1;
			num += n;
		}
	}
	else {
		int center = n;
		int left = n , right = n;
		while (left-1 >= 1 && right+1 <= swn) {
			if (switches[left-1] == switches[right+1]) {
				left--;
				right++;
			}
			else {
				break;
			}
		}
		for (int i = left; i <= right; i++) {
			switches[i] = switches[i] ? 0 : 1;
		}
	}
}
int main() {
	cin >> swn;
	for (int i = 1; i <= swn; i++) {
		cin >> switches[i];
	}
	cin >> stun;
	for (int i = 0; i < stun; i++) {
		int sx, n;
		cin >> sx >> n;
		stu.push_back({ sx,n });
	}
	
	for (int i = 0; i < stun; i++) {
		int sx = stu[i].first;
		int n = stu[i].second;
		switchsw(sx, n);

	}
	int printn = swn;
	int start = 1;
	while (printn > 20) {
		int i;
		for ( i =start; i <= 19+start; i++) {
			cout << switches[i] << ' ';
		}
		cout << '\n';
		start = i;
		printn -= 20;
	}
	for (int i = 1; i <= swn; i++)
	{
		cout << switches[i] << ' ';
		if (i % 20 == 0)
			cout << '\n';
	}

}


	

