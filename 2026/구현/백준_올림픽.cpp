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
using namespace std;


/*
초딩1학년이 푸는걸... 시간너무 잡아 끈듯
*/
vector<vector<int>>arr(1000,vector<int>(4));
bool comp(vector<int> a, vector<int> b) {
    if (a[0] == b[0]) {
        if (a[1] == b[1]) {

           return a[2] > b[2];
        }
        else return a[1] > b[1];
    }
    else return a[0] > b[0];
}
bool eq(vector<int>a, vector<int>b) {
    return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        
        cin >> arr[i][3] >> arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    int rank=0;
    sort(arr.begin(), arr.end(), comp);
    for (int i = 0; i < n; i++) {
        if (arr[i][3] == m) {
            rank = i;
            break;
        }
    }
    while (rank>0) {
        if (!eq(arr[rank], arr[rank - 1])) {
            break;
        }
        rank--;
    }
    //for (int i = 0; i < n; i++) {
    //    cout << arr[i][0] << ' ' << arr[i][1]<<' ' << arr[i][2]<<' ' << arr[i][3]<<endl;
    //}
    cout << rank + 1;
}