/*구현 문제, stack문제 오랜만.*/
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include<cmath>

using namespace std;
void timeconvert(int* hour, int* min, string time) {
    *hour = 10 * (time[0] - '0');
    *hour += (time[1] - '0');

    *min = 10 * (time[3] - '0');
    *min += (time[4] - '0');    
}
bool compare(vector<string>a, vector<string>b) {
    return a[1] < b[1];
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    sort(plans.begin(), plans.end(), compare);
    int chour, cmin, nhour, nmin;
    deque<vector<string>>dq;
    for (int i = 0;i < plans.size() - 1;i++) {
        timeconvert(&chour, &cmin, plans[i][1]);
        timeconvert(&nhour, &nmin, plans[i + 1][1]);
        int dur = stoi(plans[i][2]);
        if (chour * 60 + cmin + dur > nhour * 60 + nmin) {
            dur += (chour * 60 + cmin  - (nhour * 60 + nmin));
            dq.push_back({ plans[i][0],to_string(dur) });
        }
        else if(chour * 60 + cmin + dur == nhour * 60 + nmin){
            answer.push_back(plans[i][0]);
         }
        else {
            answer.push_back(plans[i][0]);
            int time = chour * 60 + cmin + dur;
            while (!dq.empty()) {
                vector<string>recent = dq.back();
                dq.pop_back();
                if (time + stoi(recent[1]) > nhour * 60 + nmin) {
                    int recentdur = stoi(recent[1]) - (nhour * 60 + nmin-time);
                    dq.push_back({ recent[0],to_string(recentdur) });
                    break;
                }
                else {
                    answer.push_back(recent[0]);
                    time += stoi(recent[1]);
                }
            }
        }  
    }
    answer.push_back(plans.back()[0]);
    while (!dq.empty()) {
        answer.push_back(dq.back()[0]);
        dq.pop_back();
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

    solution(plans);
}