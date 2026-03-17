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
뭔가 어떻게 이걸풀지 kmp문제인거 같긴한데
접두사=접미사인 길이를 뺴면 중복된걸 제거할수 있다.
*/
string str;
vector<int>answer;
int* pf;
void pattern_find(int len) {
    for (int i=0; i < len; i++) 
        pf[i] = 0;
    int j = 0;
    for (int i = 1; i < len; i++) {
        while (j>0&&str[i] != str[j]) {
            j = pf[j - 1];
        }
        if (str[i] == str[j]) {
            j++;
            pf[i] = j;
        }
    }
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cin >> str;
    int len = str.length();
    pf = new int[len];
    pattern_find(len);
    cout << len - pf[len - 1];

}