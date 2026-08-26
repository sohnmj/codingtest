/*
hash 문제였다.
string s=""+c;는 안되고
string s="";
s+=c; 두줄에 걸쳐서 하면 된다.
*/
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include<set>
#include<deque>
typedef long long ll;
using namespace std;
vector<int> solution(string msg) {
    vector<int> answer;
    int cur_number = 1;
    unordered_map<string, int>um;
    for (int i = 65;i < 91;i++) {
        char c = i;
        string s = "";
         s+= c;
        um[s]=cur_number++;
    }
    for (int i = 0;i < msg.size();i++) {
        string key = "";
        int j = i;
        while (j < msg.size()) {
            key += msg[j];
            
            if (um.count(key) == 0) {
                key.pop_back();
                break;
            }
            j++;
        }
        i = j - 1;
        answer.push_back(um[key]);
        if (i < msg.size() - 1) {
            key += msg[i+1];
            um[key] = cur_number++;
        }
        
    }

    return answer;
}
int main() {


    solution("KAKAO");
}