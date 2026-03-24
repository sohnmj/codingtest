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
중점을 잘못 생각한 것 같다. 이문제는 쉽게 생각하면 N의 값을 늘려가면서 주어진 숫자열의 숫자 순서대로 모두 포함되는지 확인하면 되는 문제였다.
하지만 이어쓰기를 할때 높은자리 숫자가 먼저 나오기 떄문에 주의해서 풀어야될 것 같다.
*/
int cnt[10];
vector<vector<int>>dp;
int main() {
    string str;
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> str;
    int base=1;
    int i = 0;
    int target = str[0] - 48;
    while (1) {
        int num = base;
        vector<int>arr;
        while (1) {
            if (num < 10) {
                arr.push_back(num % 10);
                break;
            }
            arr.push_back(num % 10);
            num /= 10;
        }
        for (int j = arr.size() - 1; j >= 0; j--) {
            if (arr[j] == str[i]-48) {
                i++;
                if (i == str.length()) {
                    break;
                }
            }
        }
        if (i == str.length()) {
            break;
        }
        base++;
    }

        
    cout<< base;
}