/*완전탐색으로 하면 너무 시간초과인 것 같아 그리디라는 것을 짐작했지만 결론적으로 풀이를 찾지 못했고 답을 보게 되었다. 끝부분을 정렬해서 푸는 문제 였고 
답지를 봐도 틀렸다. 너무 구현 문제처럼 접근해서 풀었더니 시간초과가 나왔다. 간단한 식으로 푸는 연습을 해야겠다.*/
#include<iostream>
#include <string>
#include <vector>
#include<deque>
#include<algorithm>
using namespace std;
bool compare(vector<int>a, vector<int> b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), compare);

    int i = 0;
    int pos = 0;
    for (vector<int> target : targets) {
        if (target[0] >= pos) {
            answer++;
            pos = target[1];
        }

    }
    return answer;
}
int main() {
    vector<vector<int>> targets = {
        {4, 5},
        {4, 8},
        {10, 14},
        {11, 13},
        {5, 12},
        {3, 7},
        {1, 4}
    };

    vector<vector<int>> b = {
        {1, 2, 1, 2},
        {2, 1, 2, 1}
    };

    cout<<solution(targets);
    

}