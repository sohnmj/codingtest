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
그냥 간단하게 생각하면 풀리는 문제였다. 
gpt한테 물어보니깐 햄버거와 사람의 위치를 따로 저장한다음 사람당 햄버거 위치 배열 왼쪽부터 조건을 채크하고 먹어야되면 된다
*/
int n,k,cnt;
string str;
int visited[20000];
void check(int idx) {
    int st = (idx - k >= 0) ? idx - k : 0;
    int ls = (idx + k < n) ? idx + k : n - 1;
    for (int i = st; i <= ls; i++) {
        if (str[i] == 'H' && visited[i] == 0) {
            visited[i] = 1;
            cnt++;
            break;
        }
    }
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    cin >> str;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'P') {
            check(i);
        }
    }

    cout << cnt;

}