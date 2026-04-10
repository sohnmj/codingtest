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
동시에 이동한 후 파이어볼을 합치는 유형의 문제에서는, 기존 상태를 유지하며 갱신하기보다 결과를 새로운 배열에 다시 구성하는 방식이 더 효율적이다.

파이어볼의 위치 정보는 별도로 저장되어 있기 때문에, mp 배열 역시 이전 상태를 유지할 필요 없이 매 턴마다 초기화한 뒤 이동이 끝난 파이어볼들을 새로 추가하면 된다.

따라서 mp에서 원소를 삭제하거나 이동시키는 과정을 반복하기보다는, 이동 후 위치에 맞게 다시 채우는 방식이 더 간단하고 오류를 줄일 수 있다.
*/
vector<int>mp[50][50];
vector<vector<int>>fireballs;
int n, m, k;
int dt[8][2] = {
	{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}
};
void movef(int ith) {
	int r = fireballs[ith][0], c = fireballs[ith][1], s = fireballs[ith][3], d = fireballs[ith][4];
	s %= n;
	r = (r + s * dt[d][0] % n + n) % n;
	c = (c + s * dt[d][1] % n + n) % n;
	fireballs[ith][0] = r;
	fireballs[ith][1] = c;
}
void mergef() {
	vector<vector<int>>temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			if (mp[i][j].size() == 1) {
				temp.push_back(fireballs[mp[i][j][0]]);
			}
			else if (mp[i][j].size() > 1) {
				int  m=0, s=0, d;
				int num = mp[i][j].size();
				for (int t = 0; t < mp[i][j].size();t++) {
					int ith = mp[i][j][t];
					m += fireballs[ith][2];
					s += fireballs[ith][3];

	
				}
				m /= 5;
				s /= num;
				if(m==0) continue;
				int odd = 0, even = 0;
				for (auto idx : mp[i][j]) {
					if (fireballs[idx][4] % 2 == 0) even++;
					else odd++;
				}
				if (odd==0||even==0) {
					for (int t = 0; t < 4; t++) {
						temp.push_back({ i,j,m,s,	t * 2 });
					}
				}
				else {
					for (int t = 0; t< 4; t++) {
						temp.push_back({ i,j,m,s,	t * 2+1 });
					}
				}

			}
		}
	}
	fireballs = temp;
}
void solutionf() {
	for (int tc = 0; tc < k; tc++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mp[i][j].clear();
			}
		}
		for (int ith = 0; ith < fireballs.size(); ith++) {
			movef(ith);
			mp[fireballs[ith][0]][fireballs[ith][1]].push_back(ith);
		}
		mergef();
	}
}
int weight() {
	int sum = 0;
	for (auto& fb : fireballs) {
		sum += fb[2];
	}
	return sum;
}
int main() {
	cin >> n>>m>>k;
	for (int i = 0; i < m; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		r--;
		c--;
		fireballs.push_back({ r,c,m,s,d });
	}
	solutionf();
	int m = weight(); cout << m;
}


	

