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
프로젝트 중에 kmp알고리즘을 사용할 부분이 있어서 공부하는 김에 풀어보았다.
조금 복잡하지만 그래도 이해를 간신히 한것 같다.
*/
string T, P;
vector<int>answer;
int* pf;
void pattern_find(int len) {
    for (int i=0; i < len; i++) 
        pf[i] = 0;
    int j = 0;
    for (int i = 1; i < len; i++) {
        while (j>0&&P[i] != P[j]) {
            j = pf[j - 1];
        }
        if (P[i] == P[j]) {
            j++;
            pf[i] = j;
        }
    }
}
void match() {
    int lent = T.length();
    int lenp = P.length();
    int j = 0;
    for (int i = 0; i < lent; i++) {
        while (j > 0 && T[i] != P[j]) {
            j = pf[j - 1];
        }
        if (T[i] == P[j]) { 
            j++;
        }
        if (j == lenp) {
            answer.push_back(i - lenp + 2);
            j = pf[j-1];
        }
    }
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    getline(cin, T);
    getline(cin, P);
    int len = P.length();
    pf = new int[len];
    pattern_find(len);
    match();
    cout << answer.size()<<'\n';
    for (auto i : answer) {
        cout << i << '\n';
    }

}