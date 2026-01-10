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



/*set를 이용해서 그래프내에서 사이클이 있는지 확인할려고 했다.만약 a, b노드가 연결된 간선이 추가되면 a, b가 모두 set에 있다면 사이클이 생긴다고 판단한다.
하지만 이 방식은 만약 a,b가 모두 set가 있다라고 해도 두 노드가 연결되어 있지 않는다면 사이클이 안생기고 이런식으로 판단하면 모두 노드가 연결되지 않을 수 있다.

그래서 정석대로 union-find를 이용하여 크루스칼 알고리즘을 사용했다.
*/
using namespace std;
int ans[101];
int find(int x) {
    if (ans[x] != x) {
        ans[x] = find(ans[x]);
        return ans[x];
    }
    else {
        return x;
    }
}
int unions(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a == b) {
        return false;
    }
    else {
        if (a < b) {
            ans[b] = a;
        }
        else {
            ans[a] = b;
        }
        return true;
    }

}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for (int i = 0; i <n; i++) {
        ans[i] = i;
    }
    sort(costs.begin(), costs.end(), [](vector<int>a, vector<int>b) {
        return a[2] < b[2];
    });
    for (auto i : costs) {
        int x = i[0];
        int y = i[1];
        if (unions(x, y)) {
            answer += i[2];
        }
    }
    int a = find(0);
    for (int i = 1; i < n; i++) {
        if (find(i) != a) {
            return -1;
        }
    }
    return answer;
}
int main() {
    vector<vector<int>> v = {
    {0, 1, 1},
    {0, 2, 2},
    {1, 2, 5},
    {1, 3, 1},
    {2, 3, 8}
    };
    cout<<solution(4,v);
}