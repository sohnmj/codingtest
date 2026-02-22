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
그냥 구현
*/
string str;
int aeiou(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return 1;
    }
    else return 0;
}
bool cmp(char a, char b) {
    if (aeiou(a) == aeiou(b)) {
        return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1) {
        cin >> str;
        if (str == "end") {
            break;
        }
        int len = str.length();
        int ct = 0;
        int ct1 = 1;
        int ps = 1;
        if (aeiou(str[0]) ){
            ct++;
        }
        for (int i = 1; i < len; i++) {
            if (str[i] == str[i-1] && (str[i] != 'e' && str[i] != 'o')) {
                ps = 0;
                break;
            }
            if (aeiou(str[i]) == 1) {
                ct++;
            }
            if (cmp(str[i], str[i - 1])) {
                ct1++;
            }
            else {
                ct1 = 1;
            }

            if (ct1 == 3) {
                ps = 0;
                break;
            }
        }
        if (ct == 0) {
            ps = 0;
        }
        cout << '<' << str << '>';
        if (ps) {
            cout << " is acceptable."<<'\n';
        }
        else {
            cout << " is not acceptable." << '\n';
        }

    }
}