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
해쉬와 정렬을 이용하여 풀었다. 그리고 문자열과 숫자를 같이 저장하기 위해서 구조체로 만들었다.
*/
typedef struct {
    string str;
    int count;
}ss;
int n, m;
unordered_map<string, int>strmap;
vector<ss>sortedstr;
bool compare(ss a, ss b) {
    if (a.count == b.count) {
        if (a.str.length() == b.str.length()) {
            return a.str < b.str;
        }
        return a.str.length() > b.str.length();
    }
    return a.count > b.count;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n>>m;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        if (str.length() < m) {
            continue;
        }
        strmap[str]++;
    }
    for (auto i : strmap) {
        ss temp;
        temp.str = i.first;
        temp.count = i.second;
        sortedstr.push_back(temp);
    }
    sort(sortedstr.begin(), sortedstr.end(), compare);
    for (auto i : sortedstr) {
        cout << i.str << '\n';
    }
}