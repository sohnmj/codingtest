/*내일보자*/
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include<cmath>
#include<queue>
#include <unordered_map>
#include<set>
#include <sstream>
#include<iostream>
typedef long long ll;
using namespace std;
vector<vector<int>>arr = { {3000,2000,1000},{200,100},{20,10},{1,2} };
unordered_map<string, int>um;
vector<string> split(string& str) {
    vector<string> result;
    stringstream ss(str);
    string word;

    while (ss >> word) {
        if (word == "and") {
            continue;
        }
        result.push_back(word);
    }

    return result;
}
int binary_search(int target,vector<int>score) {
    int len=score.size();
    int st = 0,ls=len-1;
    int md;
    int result=-1;
    while (st <= ls) {
        md = (st + ls) / 2;
        if (score[md] < target) {
            st = md + 1;
        }
        else if (score[md] == target) {
            result = md;
            break;
        }
        else if (score[md] > target) {
            result = md;
            ls = md - 1;
        }
    }
    return result;
}
int getSc(vector<string>& cases) {
    int sym = 0;
    for (int i = 0;i < 4;i++) {
        sym += um[cases[i]];
    }
    return sym;
}
void init() {
    um["java"] = 1000;
    um["python"] = 2000;
    um["cpp"] = 3000;
    um["frontend"] = 100;
    um["backend"] = 200;
    um["junior"] = 10;
    um["senior"] = 20;
    um["pizza"] = 1;
    um["chicken"] = 2;
}
void dfs(int d,int sym,vector<string>& cases,vector<int>&syms) {
    if (d == 4) {
        syms.push_back(sym);
    }
    else {
        if (cases[d] == "-") {
            for (int i : arr[d]) {
                dfs(d + 1, sym + i, cases,syms);
            }
        }
        else {
            dfs(d + 1, sym + um[cases[d]], cases, syms);
        }
    }
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<int>symscore[3223];
    vector<string>cases;
    init();
    for(string text:info){
        cases = split(text);
        int score = stoi(cases.back());
        int sym=getSc(cases);
        symscore[sym].push_back(score);
    }
    //for (int i = 0;i <= 2111;i++) {
    //    sort(arr[i].begin(), arr[i].end());
    //}
    for (auto q : query) {
        cases = split(q);
        int score = stoi(cases.back());
        vector<int>syms;
        dfs(0, 0, cases, syms);
        vector<int>meetsym;
        for (auto i : syms) {
            for (auto j : symscore[i]) {
                meetsym.push_back(j);
            }
        }
        sort(meetsym.begin(), meetsym.end());
        int idx=binary_search(score,meetsym );
        if (idx < 0) {
            answer.push_back(0);
        }
        else {
            answer.push_back(meetsym.size() - idx);
        }
    }
    return answer;
}
int main() {
    std::vector<std::vector<int>> vec = { {1, 1, 100, 97} };
    std::vector<std::string> info = {
        "java backend junior pizza 150",
        "python frontend senior chicken 210",
        "python frontend senior chicken 150",
        "cpp backend senior pizza 260",
        "java backend junior chicken 80",
        "python backend senior chicken 50"
    };
    std::vector<std::string> rawData = {
        "- and - and - and - 150"
    };
    vector<int>ans=solution(info,rawData);
    for (int i : ans) {
        cout << i <<" ";
    }
}