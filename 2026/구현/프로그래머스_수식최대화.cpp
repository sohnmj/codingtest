/*
옛날에 벡터를 반복 탐색할때 원소를 지우면 에러가 난다고 생각해서 visited를 사용해서 했는데 조금 복잡해진거 같다.
찾아보니 vector.size()는 erase를 하면 반복문 돌아가면서 최신화가 된다고 한다. 그래서 반복자만 잘 생각해주면 안전하게 코드를 돌릴 수 있을 것 같다.
*/
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include<set>
typedef long long ll;
using namespace std;
ll calculate(int idx, char op, vector<ll>& digit, vector<int>&visited) {
    ll n1 ,n2;
    int idx1 = idx, idx2 = idx+1;
    while (visited[idx1] && idx1 >= 0) {
        idx1--;
    }
    n1 = digit[idx1];
    while (visited[idx2] && idx2 < digit.size()) {
        idx2++;
    }
    n1 = digit[idx1];
    n2 = digit[idx2];
    visited[idx2] = 1;

    ll result;
    if (op == '-') {
         result= n1 - n2;
    }
    else if (op == '+') {
        result = n1 +n2;
    }
    else {
        result = n1 * n2;
    }
    digit[idx1] = result;
    return result;
}
long long solution(string expression) {
    long long answer = 0;
    vector<ll>digit;
    vector<char>opt;
    vector<char>opts = {'*','+','-'};
    for (int i = 0;i < expression.size();i++) {
        string s="";
        while (48 <= expression[i] && expression[i] <= 57&&i<expression.length()) {
            s += expression[i];
            i++;
        }
        if (s.length() == 0) {
            opt.push_back(expression[i]);

        }
        else {
            digit.push_back(stoll(s));
            i--;
        }
    }
    do {
        ll mx = 0;
        vector<int>visited(100, 0);
        vector<ll>ndigit = digit;
        for (char copt : opts) {
            
            
            for (int i = 0;i < opt.size();i++) {
                if (copt == opt[i]) {
                    ll temp=calculate(i, copt, ndigit,visited);
                    mx = abs(temp);

                }

            }


        }
        if (answer < mx) {
            answer = mx;
        }
    } while (next_permutation(opts.begin(), opts.end()));
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
    solution("100-200*300-500+20");
  
}