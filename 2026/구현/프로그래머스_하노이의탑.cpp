
/*
정답을 조금 보고 풀긴 했지만 나름 생각한 문제
그냥 재귀 문제의 어려운 버전 같았다. 처음에는 복잡한 과정이 있다고 생각했는데 막상 점화식을 구현하니 매우 간단한 문제였다.

점화식의 핵심은 n번째 원판을 from에서 to로 옮기기 위해서는 n-1번째 원판을 from에서 by로 옮긴 후에 옮겨야한다. 그리고 모든 원판을 to로 옮겨
야하므로 n-1원판도 n원판을 to로 옮긴 후에 바로 by에서 to로 옮겨준다. 이것을 재귀적으로 반복하면 된다.
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
void movehanoi(int n, int from, int by, int to, vector<vector<int>>& answer) {
    if (n == 1) {
        answer.push_back({ from,to });
    }
    else {
        movehanoi(n - 1, from, to, by, answer);
        answer.push_back({ from,to });
        movehanoi(n - 1, by, from, to, answer);
    }
}
vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    movehanoi(n, 1, 2, 3, answer);
    return answer;
}
int main() {


    cout<<solution("FRANCE", "french");
}