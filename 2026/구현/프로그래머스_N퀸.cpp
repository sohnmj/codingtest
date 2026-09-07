
/*
뭔가 허전한 풀이였다. 수학 문제여서 뭐 딱히 적을게 없다.
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
int answer = 0;
void dfs(int row,int n, vector<set<int>>& visit) {
    if (row == n+1) {
        answer++;
        return;
    }
    for (int i = 0;i < n;i++) {
        if (!visit[0].count(i) && !visit[1].count(row + i) && !visit[2].count(n - row + i)) {
            visit[0].insert(i);
            visit[1].insert(i+row);
            visit[2].insert(n-row+i);
            dfs(row + 1, n, visit);
            visit[0].erase(i);
            visit[1].erase(i + row);
            visit[2].erase(n - row + i);
        }
    }

}
int solution(int n) {
    vector<set<int>>visit(4);
    dfs(1, n, visit);

    return answer;
}
int main() {


    cout<<solution("FRANCE", "french");
}