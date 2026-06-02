/*bfs.*/
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include<cmath>

using namespace std;
int w, h;
int leftwall(int stx, int sty, int lsx, int lsy) {
    if (stx == lsx) {
        if (sty > lsy) {
            return 1e9;
        }
    }
    return (stx - lsx)*(stx - lsx) + (sty + lsy) * (sty + lsy);
}
int rightwall(int stx, int sty, int lsx, int lsy) {
    if (stx == lsx) {
        if (sty <lsy) {
            return 1e9;
        }
    }
    return (stx - lsx) * (stx - lsx) + (2*w-(sty + lsy)) * (2 * w - (sty + lsy));
}
int downwall(int stx, int sty, int lsx, int lsy) {
    if (sty == lsy) {
        if (stx >lsx) {
            return 1e9;
        }
    }
    return (stx + lsx) * (stx + lsx) + (sty - lsy) * (sty - lsy);
}
int upwall(int stx, int sty, int lsx, int lsy) {
    if (sty == lsy) {
        if (stx < lsx) {
            return 1e9;
        }
    }
    return (2*h-(stx + lsx)) * (2 * h - (stx + lsx)) + (sty - lsy) * (sty - lsy);
}
vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    w = m;
    h = n;
    for (auto ball: balls) {
        int lsx = ball[0], lsy = ball[1];
        int right = rightwall(startX, startY, lsx, lsy);
        int left = leftwall(startX, startY, lsx, lsy);
        int down = downwall(startX, startY, lsx, lsy);
        int up = upwall(startX, startY, lsx, lsy);
        int mindistance =1e9;
        mindistance = min(mindistance, right);
        mindistance = min(mindistance, left);
        mindistance = min(mindistance,down);
        mindistance = min(mindistance, up);
        answer.push_back(mindistance);
    }
    return answer;
}

int main() {
    vector<vector<string>> plans = {
        {"science", "12:40", "50"},
        {"music", "12:20", "40"},
        {"history", "14:00", "30"},
        {"computer", "12:30", "100"}
    };

    vector<vector<int>> b = {
        {1, 2, 1, 2},
        {2, 1, 2, 1}
    };

    cout<<solution( { "...D..R", ".D.G...", "....D.D", "D....D.", "..D...." });
    cout << "╬х©╣го";
}