
/*
이 문제의 화나는 점은 항공편이 동일한것이 2번 있을 수 있다는 점과 모든 항공을 경유하는 경로로 가야 한다는 것이다.
*/
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, vector<string>> adj; // 각 공항별 목적지 목록
vector<string> answer;

void dfs(string airport) {
    // 목적지가 더 이상 없을 때까지 방문
    while (!adj[airport].empty()) {
        string next = adj[airport].back(); // 오름차순으로 가장 작은 목적지 선택
        adj[airport].pop_back(); // 방문한 티켓은 제거
        dfs(next); // 다음 공항으로 DFS
    }
    answer.push_back(airport); // 경로가 끝날 때마다 공항 추가
}

vector<string> solution(vector<vector<string>> tickets) {
    // 티켓을 그래프 형태로 변환
    for (auto& ticket : tickets) {
        adj[ticket[0]].push_back(ticket[1]);
    }

    // 각 출발지에서의 목적지를 오름차순으로 정렬
    for (auto& pair : adj) {
        sort(pair.second.begin(), pair.second.end(), greater<string>()); // 오름차순 정렬
    }

    // ICN부터 시작
    dfs("ICN");

    // 답은 반대로 저장되므로 뒤집어서 반환
    reverse(answer.begin(), answer.end());
    return answer;
}
int main() {
    std::vector<std::vector<std::string>> flights = {
    {"EZE","TIA"}, {"EZE","HBA"}, {"AXA","TIA"}, {"ICN","AXA"}, {"ANU","ICN"},
    {"ADL","ANU"}, {"TIA","AUA"}, {"ANU","AUA"}, {"ADL","EZE"}, {"ADL","EZE"},
    {"EZE","ADL"}, {"AXA","EZE"}, {"AUA","AXA"}, {"ICN","AXA"}, {"AXA","AUA"},
    {"AUA","ADL"}, {"ANU","EZE"}, {"TIA","ADL"}, {"EZE","ANU"}, {"AUA","ANU"}
    };
    vector<string>arr= solution(flights);
    for (auto i : arr) {
        cout << i << endl;
    }

}