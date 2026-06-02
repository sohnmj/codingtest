/*구현 문제인데 실수를 너무 많이 한듯 ㅠㅠ.*/
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include<cmath>

using namespace std;

int tiremine[3][3] = { {1,1,1},{5,1,1},{25,5,1} };
int cacTire(vector<int> use, vector<string> minerals) {
    int count = 5;
    int idx = 0;
    int tiresum = 0;
    for (string mineral : minerals) {
        if (count == 0) {
            idx++;
            if (idx == use.size()) break;
            count = 5;
        }
        int mineralnum;
        if (mineral == "diamond") {
            mineralnum = 0;
        }
        else if (mineral == "iron") {
            mineralnum = 1;
        }
        else {
            mineralnum = 2;
        }
        tiresum += tiremine[use[idx]][mineralnum];
        count--;
    }
    return tiresum;
}
int solution(vector<int> picks, vector<string> minerals) {
    int mintire = 1e9;

    int mine = (minerals.size() % 5 == 0) ? minerals.size() / 5 : minerals.size() / 5 + 1;

    vector<int>use;
    //int temp = mine;
    //for (int i = 0;i < 3;i++) {
    //    if (picks[i] < temp) {
    //        use[i] += picks[i];
    //        temp -= picks[i];
    //    }
    //    else if (picks[i] >= temp) {
    //        use[i] += picks[i];
    //        break;
    //    }
    //}
    int pi = 0;
    for (int i = 0;i < mine;i++) {
        while (picks[pi] == 0) {
            pi++;
            if (pi == 3) {
                break;
            }
        }
        if (pi == 3) {
            break;
        }
        use.push_back(pi);
        picks[pi]--;
    }
    do {
        int tired = cacTire(use, minerals);
        if (tired < mintire) {
            mintire = tired;
        }
    } while (next_permutation(use.begin(), use.end()));
    return mintire;
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

    cout<<solution({0, 1, 1}, { "diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond" });
    cout << "안영하";
}