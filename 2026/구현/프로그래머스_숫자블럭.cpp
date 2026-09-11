
/*
아쉬운점은 문제를 제대로 안읽은 것이다. 숫자 블럭은 천만까지만 있지만 문제를 풀때 이를 고려하지 않았다. 항상 엣지 케이스를 경계하자.
*/



#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include<set>
#include<deque>
#include<cmath>
typedef long long ll;
using namespace std;


vector<int> solution(long long begin, long long end) {
    vector<int> answer(end - begin + 1, 0);
    for (ll i = begin;i <= end;i++) {
        bool isprime = true;
        ll maxc = 1;
        for (ll j = 2;j <= sqrt(i);j++) {

            if (i % j == 0) {
                isprime = false;
                if (i / j <= 10000000) {
                    answer[i - begin] = i / j;

                    break;
                }
                maxc = j;
            }
        }
        if (isprime && i != 1) {
            answer[i - begin] = 1;
        }
        if (!isprime && answer[i - begin] == 0) {
            answer[i - begin] = maxc;
        }
    }
    return answer;
}int main() {


    solution(1, 10);
}