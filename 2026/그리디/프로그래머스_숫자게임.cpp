/*
약간 그리드스러운 문제였다. 근데 B를 기준으로 했으면 erase안써도 되서 더 시간 복잡도가 단축되었을 것 같다.
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
#include<queue>
typedef long long ll;
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

        
    
    for (int i = A.size() - 1;i >= 0;i--) {
        cout << A[i] << ' ' << B.front() << endl;
        if (A[i] > B.back()) {
            B.erase(B.begin());
        }
        else {
            
            B.pop_back();
            answer++;
        }
    }
    return answer;
}