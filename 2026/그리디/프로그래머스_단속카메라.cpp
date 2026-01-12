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



/*
처음 풀이에서는 진입 시점을 가지고 정렬하였다. 
감시 카메라의 위치는 고려하지 않은 실수를 하였고 그 결과 진입시점과 진출시점 모두 감시 카메라가 설치되어 있다고
착각하고 문제를 풀었다. 
반복문에서 현재 선택된 차의 진출시점보다 작은 진입 시점을 가지고 있는 차들이 같은 감시 카메라에 포착된다고 생각하여 잘못된 
풀이를 하게 되었다. 
예를들어
(           )
         ()
     ( )
인 경우 1개의 카메라가 아니라 2개의 카메라가 필요하다.
그래서 진출 시점에 카메라의 위치를 고정하였고 그러기 위해서 진출 시점을 가지고 정렬하여 풀어(chat gpt도움 받음) 정답을 맞췄다.
*/
using namespace std;
int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), [](vector<int>a, vector<int> b) {
        return a[1] < b[1];
        });
    int cur = 0;
    int i = 0;
    int n=routes.size();
    while (cur < n) {
        i++;
        while (i<n&&routes[cur][1]>=routes[i][0]) {
            i++;
        }
        cur = i;
        answer++;
    }
    return answer;
}

int main() {
    vector<vector<int>> v = {
        {-20, -15},
        {-14, -5},
        {-18, -13},
        {-5, -3},
    
    };
    cout<<solution(v);
}