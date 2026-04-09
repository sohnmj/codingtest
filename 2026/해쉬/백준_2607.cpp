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
unordered_map 주의 할점
count 함수는 갯수를 반환하는게 아니라 존재하는지만 체크해서 갯수가 0이더라도 존재하면 1을 반환한다..
*/
unordered_map<char, int>element[100];
int main() {
	string stand;
	vector<string>str;
	int n;
	cin >> n;
	cin >> stand;
	for (int i = 1; i < n; i++) {
		string temp;
		cin >> temp;
		str.push_back(temp);
		//단어 구성 개수 구하기
		for (auto c : stand) {
			element[i - 1][c]++;
		}
	}
	int count=0;
	for (int i = 0; i < n - 1; i++) {
		int dif = 0;
		for (auto c : str[i]) {
			if (element[i][c]== 0) {
				dif++;
				if (dif > 1) {
					break;
				}
			}
			else {
				element[i][c]--;
			}
		}
		int remain = 0;
		for (auto c : stand) {
			remain += element[i][c];
			if (element[i][c] > 0) {
				element[i][c]--;
			}
		}
		if (dif+remain <=1) {
			count++;
		}
		else if (dif == remain&&dif+remain==2) {
			count++;
		}
	}
	cout << count;
}


	

