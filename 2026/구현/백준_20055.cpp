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
구현문제다
차근차근 푸니깐 맞았다.
*/
int n,k;
int mp[200];
void nextbelt() {
    int temp = mp[0];
    for (int i = 2*n-1; i >0; i--) {
        mp[(i + 1) % (2 * n)] = mp[i];
    }
    mp[1] = temp;
}
vector<vector<int>>belts;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> k;
        for (int i = 0; i < 2 * n; i++) {
        int d;
        cin >> d;
        belts.push_back({ 0,d });
    }
    for (int i = 0; i < 2 * n; i++) {
        mp[i] = i;
    }
    int t=0;
    while (1) {
        nextbelt();
        if (belts[mp[n - 1]][0]) {
            belts[mp[n - 1]][0] = 0;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (belts[mp[i]][0]) {
                int nb = mp[i + 1];
                if (!belts[nb][0] && belts[nb][1] > 0) {
                    belts[mp[i]][0] = 0;
                    belts[nb][0] = 1;
                    belts[nb][1]--;
                }
            }
        }
        if (belts[mp[n - 1]][0]) {
            belts[mp[n - 1]][0] = 0;
        }
        if (belts[mp[0]][1] > 0) {
            belts[mp[0]][1]--;
            belts[mp[0]][0] = 1;
        }
        t++;
        int cnt = 0;
        for(int i = 0; i < 2 * n; i++) {
            if (belts[i][1] == 0) {
                cnt++;
                if (cnt == k) {
                    break;
                }
            }
        }
        if (cnt == k) {
            break;
        }
        
    }
    cout << t;


}