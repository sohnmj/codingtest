/*
쉬운 문제인데 너무 오래걸렸다. 한번 풀때 제대로 풀어야될것 같다.*/
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include<set>
typedef long long ll;
using namespace std;
int dt[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int solution(string dirs) {
    int answer = 0;
    set<vector<int>>visited;
    int x = 0, y = 0;
    for (auto dir : dirs) {
        int nx, ny;
        if (dir == 'U') {
            nx = x + dt[0][0];
            ny = y + dt[0][1];
        }
        else if (dir == 'D') {
            nx = x + dt[1][0];
            ny = y + dt[1][1];
        }
        else if (dir == 'R') {
            nx = x + dt[2][0];
            ny = y + dt[2][1];
        }
        else {
            nx = x + dt[3][0];
            ny = y + dt[3][1];
        }
        if (nx < -5 || nx>5 || ny < -5 || ny>5) {
            continue;
        }
        vector<int>line;
        if (x < nx||(x==nx&&y<ny)) {
             line= { x,y,nx,ny };
        }
        else {
            line = { nx,ny,x,y };
        }
        if (visited.count(line)) {
            x = nx;
            y = ny;
            continue;
        }
        answer++;
        visited.insert(line);
        x = nx;
        y = ny;
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
    solution("ULURRDLLU");
  
}