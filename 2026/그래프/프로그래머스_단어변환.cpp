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
/*한번에 풀어서 기분이 좋다 단순한 그래프 탐색 문제인데 인접 노드 약간 꼬아서 낸 문제인 것 같다*/
using namespace std;
int vis[50] = { 0, };
int comp(string a, string b) {
    int n = a.length();
    int count = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            count--;
        }
        if (count < 0) {
            return 0;
        }
    }
    return 1;
}
int bfs(string begin,string target,vector<string> words) {
    queue<pair<string, int>>que;
    int n = words.size();
    que.push({ begin,0 });
    while (!que.empty()) {
        pair<string, int>cur;
        cur=que.front();
        que.pop();
        string str = cur.first;
        int d = cur.second;
        if (target == str) {
            return d;
        }
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                if (comp(str, words[i])) {
                    que.push({ words[i],d + 1 });
                    vis[i] = 1;
                }
            }
        }
    }
    return 0;

}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    answer = bfs(begin, target, words);
    return answer;
}
int main() {
    vector<string> v = {
   "hot", "dot", "dog", "lot", "log"
    };
    cout<<solution("hit", "cog", v);
}