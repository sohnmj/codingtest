
/*
오랜만에 제대로된 구현 문제를 푸는것 같다.
*/
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include<queue>
using namespace std;
typedef struct robot {
    int sx;
    int sy;
    int dx;
    int dy;
    int ith;
};
int board[100][100];
vector<robot> robots;
int robot_cnt;
int answer;
void robots_moves(vector<vector<int>> &points,vector<vector<int>>&routes) {
    for (int i = 0;i < robots.size();i++) {
        robot rb = robots[i];
        if (rb.ith == -1) {
            rb.ith = -2;
            board[rb.sx][rb.sy]--;
            robots[i] = rb;
            continue;
        }
        if (rb.ith == -2) {
            continue;
        }
        board[rb.sx][rb.sy]--;
        //이동
        if (rb.dx - rb.sx != 0) {
            if (rb.dx - rb.sx > 0) {
                rb.sx++;
            }
            else {
                rb.sx--;
            }
        }
        else {
            if (rb.dy - rb.sy > 0) {
                rb.sy++;
            }
            else {
                rb.sy--;
            }
        }

        if (rb.sx == rb.dx && rb.sy == rb.dy) {
            if (rb.ith == routes[i].size() - 2) {
                rb.ith = -1;
            }
            else {
                rb.ith++;
                rb.dx = points[routes[i][rb.ith+1]-1][0] - 1;
                rb.dy = points[routes[i][rb.ith+1]-1][1] - 1;
            }
        }
        robots[i] = rb;

    }
}
void danger() {
    for (auto rb : robots) {
        if (rb.ith == -2) {
            continue;
        }
        if (board[rb.sx][rb.sy] == 1) {
            answer++;
        }
        board[rb.sx][rb.sy]++;
        robot_cnt = 1;

    }
}
int solution(vector<vector<int>> points, vector<vector<int>> routes) {

    for (auto i : routes) {
        int j = i.front();
        int ds = i[1];
        robot rt;
        rt.sx = points[j - 1][0]-1;
        rt.sy = points[j - 1][1]-1;
        rt.dx = points[ds-1 ][0] - 1;
        rt.dy = points[ds-1][1] - 1;
        rt.ith=0;
        robots.push_back(rt);
        if (board[rt.sx][rt.sy] == 1) {
            answer++;
        }
        board[rt.sx][rt.sy]++;
    }
    while (1) {
        robots_moves(points,routes);
        danger();
        if (!robot_cnt) {
            break;
        }
        robot_cnt = 0;
    }
    return answer;
}
int main() {
    vector<vector<int>> a = {
    {1, 1},
    {1, 3}
    };

    vector<vector<int>> b = {
        {1, 2, 1, 2},
        {2, 1, 2, 1}
    };

    cout<<solution(a,b);
    

}