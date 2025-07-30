#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
bool compare(pair<int, double>a, pair<int, double>b) {
    if (a.second != b.second) {
        return a.second > b.second;
    }
    else {
        return a.first < b.first;
    }
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>>rate;
    int pre = 0;
    sort(stages.begin(), stages.end());
    for (int i = 1; i <= N; i++) {
        int jin = 0; int a = stages.size(); int c = stages.size();
        for (int j = pre; j < stages.size(); j++) {
            if (jin == 0 && i <= stages[j]) {
                a = j;
                jin = 1;
            }
            if (i < stages[j]) {
                c = j;
                
                break;
            }
            
        }
        if (a != stages.size()) {
            double r = (double)(c - a) / (stages.size() - a);
            rate.push_back(make_pair(i, r));
        }
        else {
            rate.push_back(make_pair(i, 0));
        }
        
    }
    sort(rate.begin(), rate.end(), compare);
    for (auto it : rate) {
        answer.push_back(it.first);
    }
    return answer;
}

int main() {
    vector<int>arr = { 4,4,4,4,4};
    for (auto it : solution(4, arr)) {
        cout << it;
    }
}