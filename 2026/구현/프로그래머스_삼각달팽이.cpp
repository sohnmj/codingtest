/*
위치 계산 대신 현재 좌표(x, y) 상태를 유지하며 이동
이동할 방향은 3가지(아래, 오른쪽, 대각선 위)가 순환(i % 3)
방향이 바뀔 때마다 채워야 하는 칸의 수가 n부터 1씩 감소
이전 좌표를 그대로 이어서 전진하므로 인덱스 수식이 필요 없음.
내코드를 위의 설명 처럼 바꾸면 더 좋았을 듯 싶다.
*/
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;


vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>>mp(n, vector<int>(n));
    int i = 1;
    int limit = n*(n + 1) / 2;
    int col = 0;
    int nth = n;
    int row = n - 1;
    while (i <= limit) {
        for (int j = 0;j < nth;j++) {
            mp[j+col*2][col] = i++;
        }
        col++;
        nth--;
        for (int j = 0;j < nth;j++) {
            mp[row][n - row + j] = i++;
        }
        row--;
        nth--;
        for (int j = 0;j < nth;j++) {
            mp[row-j][ n-2+nth-row - j] = i++;
        }
        nth--;

    }
    for (int i = 0;i < n;i++) {
        for (int j = 0;j <= i;j++) {
            answer.push_back(mp[i][j]);
        }
    }
    return answer;
}
int main() {
    vector<int> vec = { 2,3,4 };

    std::vector<std::string> rawData = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<vector<int>> grid = {
    {1, 1, 0, 0},
    {1, 0, 0, 0},
    {1, 0, 0, 1},
    {1, 1, 1, 1}
    };
    vector<int>ans=solution(6);
    for( auto i : ans) {
        cout << i <<" ";
    }
}