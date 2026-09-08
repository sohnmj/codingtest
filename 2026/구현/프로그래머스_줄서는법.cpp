
/*
수학 문제여서 뭐 딱히 적을게 없다. 보완할점은 1based인지 0based인지 하나 정해놓고 하면 지금처럼 나머지에 따라 분기를 줄일 수 있어
편하게 풀수 있을 것이다.
*/


#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include<set>
#include<deque>
typedef long long ll;
using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    ll q = 1;
    vector<int>arr;
    for (int i = 1;i <= n;i++) {
        arr.push_back(i);
    }
    for (int i = n - 1;i >= 1;i--) {
        q *= (ll)i;
    }
    for (int i = n-1;i > 0;i--) {
        int item = k / q;
        if (k % q != 0) {
            item++;
        }
        answer.push_back(arr[item-1]);
        arr.erase(arr.begin() + item - 1);

        k -= q * (item-1);
        q /= i;
    }
    answer.push_back(arr[0]);
    return answer;
}
int main() {


    solution(3, 5);
}