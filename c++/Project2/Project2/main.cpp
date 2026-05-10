
/*
그냥 구현문제
*/
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include<queue>
using namespace std;
int server[24];
int solution(vector<int> players, int m, int k) {
    int answer = 0;
    for (int i = 0;i < 24;i++) {
        int player = players[i];
        if ((server[i] + 1) * m <= player) {
            int plus_server = player / m - server[i];
            answer += plus_server;
            for (int j = 0;j < k;j++) {
                if(i + j < 24) {
                    server[i + j]+=plus_server;
                }
            }
        }
    }
    return answer;
}
int main() {
    std::vector<int>vectors = { 0, 2, 3, 3, 1, 2, 0, 0, 0, 0, 4, 2, 0, 6, 0, 4, 2, 13, 3, 5, 10, 0, 1, 5};

    cout<<solution(vectors,3,5);
    

}