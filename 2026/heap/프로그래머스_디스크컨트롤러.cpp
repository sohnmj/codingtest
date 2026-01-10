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
    처음에는 당연히 현재 시간(cur)일 시점에 프로세스가 대기열(pq)에 반드시 존재안할 수도 있는데 아무 생각 없이 풀어서 
    처음부터 대기열에(pq) 프로세스를 모두 넣고 풀이했음. 
    그래서 대기열(프로세스가 모두 삽입된)에 현재시간(cur) 이하인 요청시간을 갖는 프로세스를 찾는데
    그 조건을 만족하는 프로세스가 없는 경우에는 무한 루프를 돌게 되어 시간초과가 됨.

    이 문제를 해결하기 위해 그래서 그냥 시간의 흐름을 기준으로 풀이를 하게됨
*/
struct Node {
    int a, b, c;

    bool operator<(const Node& other) const {
        if (b != other.b)
            return b > other.b;
        else {
            if (a != other.a)
                return a > other.a;
            else
                return c > other.c;
        }
             
    }
};
int solution(vector<vector<int>> jobs) {

    priority_queue<Node> pq;
    vector<vector<int>> sj;
    int n = jobs.size();
    for (int i = 0; i < n; i++) {
        sj.push_back({ jobs[i][0],jobs[i][1],i });
    }
    sort(sj.begin(), sj.end(), [](vector<int>a, vector<int>b) {
        return a[0] < b[0];
        });
    int time = 0;
    int cur = 0;
    int done = 0;
    int index = 0;
    while (n != done) {
        while (index < n && cur >= sj[index][0]) {
            pq.push({ sj[index][0],sj[index][1],sj[index][2] });
            index++;
        }
        Node node;
        if (!pq.empty()) {
            node = pq.top();
            pq.pop();

            cur += node.b;
            time += (cur - node.a);
            done++;
        }
        else {
            cur++;
        }
    }
    return time/n;
}
int main() {
    vector<vector<int>>arr = { {0,3},{1,9},{3,5} };
    cout<<solution(arr);
}