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
자괴감든다 그냥 구멍이 나면 메꾸고 또 구멍이 나면 메꾸고 임시방편으로 하다보니 운좋게 맞은 문제였다. 반례도 못찾고 그냥 힘들어진다

순위를 먼저 구하고 랭킹리스트에 벗어나는지 안 벗어나는지 확인하면 될 것을 

조건문 법벅으로 풀었다
반례 
1.n이 0이라면?
2.m이 배열 점수에서 끝에 있다면
3.
*/
int n,m,p;
vector<pair<int,int>>arr;
bool compare(pair<int,int> a, pair<int,int> b) {
    return a.first > b.first;
}
int main() {

    cin >> n>>m>>p;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back({ x,1 });
    }
    int index=0;
    int cur = 1;
    sort(arr.begin(), arr.end(), compare);
    for (int i = 0; i < n; i++) {
        if (i > 0){
            if (arr[i].first != arr[i - 1].first) {
                cur=i+1;
            }
        }
        arr[i].second = cur;
        if (arr[i].first < m) {
            index = i;
            break;
        }
        else if (i == n - 1) {
            index = n;
        }
    }


    if (index > p - 1) {
        cout << -1;
    }
    else {
        if (n == 0||index==0) {
            cout << 1;
        }
        else if (m == arr[index-1].first) {
            cout << arr[index - 1].second;
        }
        else if (index < n) {
            cout << arr[index].second;
        }
        else {
            cout << n+1;
        }
    }
        
}