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
너무 복잡하게 생각했다. 문자열의 길이가 짝수인지 홀수인지는 중요하지 않았다. 짝수인지 홀수인지 구분하는 순간 구분해야될게 많아진다.
그저 문자열에서의 펠린드룸이 가능한 문자열을 0부터 n-1까지 순서대로 확인하고 펠린드룸이 되는 s[i,n-1]문자열이 확인이 되면 n+i을 출력하면 된다.
bool isPalindrome(string s, int l, int r){
    while(l < r){
        if(s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    int n = s.size();

    for(int i = 0; i < n; i++){
        if(isPalindrome(s, i, n-1)){
            cout << n + i;
            break;
        }
    }
}
*/

int main() {
    string s;
    int n=0;
    cin >> s;
    int len = s.length();
    if (len == 1) {
        cout << 1;
    }
    else {
        int cent = 2 * len - 1;
        int st;
        int dt;
        if (len % 2 == 0) {
            st = len / 2;
            dt = 1;
            for (int i = st; i < len; i++) {
                int jin = 1;
                for (int j = i; j < len; j++) {
                    if (s[j] != s[2 * i - 1 - j]) {
                        jin = 0;
                        break;
                    }
                }
                if (jin == 1) {
                    cent = 2 * i;
                    break;
                }

                jin = 1;
                
                for (int j = i + dt; j < len; j++) {
                    if (s[j] != s[2 * (i - 1 + dt) - j]) {
                        jin = 0;
                        break;
                    }
                }
                if (jin == 1) {
                    cent = 2 * (i + dt - 1) + 1;
                    break;
                }
            }
        }
        else {
            st = len / 2 + 1;
            dt = 0;
            for (int i = st; i < len; i++) {
                int jin = 1;
                for (int j = i + dt; j < len; j++) {
                    if (s[j] != s[2 * (i - 1 + dt) - j]) {
                        jin = 0;
                        break;
                    }
                }
                if (jin == 1) {
                    cent = 2 * (i + dt - 1) + 1;
                    break;
                }

                jin = 1;
                for (int j = i; j < len; j++) {
                    if (s[j] != s[2 * i - 1 - j]) {
                        jin = 0;
                        break;
                    }
                }
                if (jin == 1) {
                    cent = 2 * i;
                    break;
                }
            }
        }

        cout << cent;
    }
    
}