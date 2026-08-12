/*
그냥 재귀 문제였던 것 같다. 문제를 풀다보니 그냥 2개의 점 전부를 인수로 주기보다는 그냥 중심 점하나와 그 배열의 길이를 줬다면 조금더 깔끔했을 것 같다.
*/
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;
int ocnt = 0,zcnt=0;
void dfs(pair<int,int>d1,pair<int,int>d2,vector<vector<int>>& arr) {
    int x1 = d1.first, x2 = d2.first, y1 = d1.second, y2 = d2.second;
    if (x1 == x2) {
        if (arr[x1][y1])ocnt++;
        else zcnt++;
    }
    else {
        int stand = arr[x1][y1];
        int jin = 1;
        for (int i = x1;i <= x2;i++) {
            for (int j = y1;j <= y2;j++) {
                if (stand !=arr[i][j]) {
                    jin = 0;
                    break;
                }
            }
            if (jin == 0) {
                break;
            }
        }
        if (jin) {
            if (stand)ocnt++;
            else zcnt++;
        }
        else {
            int len = (x2 - x1 + 1)/2;
            dfs({ x1,y1 }, { x1 + len - 1,y1 + len - 1 }, arr);
            dfs({ x1+len,y1 }, { x1+len + len - 1,y1 + len - 1 }, arr);
            dfs({ x1,y1 + len }, { x1 + len - 1,y1 + 2 * len - 1 }, arr);
            dfs({ x1+len,y1 + len }, { x1 + 2*len - 1,y1 + 2 * len - 1 }, arr);
        }
    }
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int size = arr.size();
    dfs({ 0,0 }, { size - 1,size - 1 }, arr);
    answer.push_back(zcnt);
    answer.push_back(ocnt);
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
    vector<int>ans=solution(grid);
    for( auto i : ans) {
        cout << i <<" ";
    }
}