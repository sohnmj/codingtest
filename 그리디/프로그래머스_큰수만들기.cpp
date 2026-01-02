#include<iostream>
#include <string>
#include <vector>
#include<map>
#include<queue>
#include<stack>
#include<utility>
#include<algorithm>
#include<cmath>
#include<set>

#include <unordered_map>

//스텍으로 풀기
using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> st;

    for (char c : number) {
        
        while (!st.empty() && k > 0 && st.top() < c) {
            st.pop();
            k--;
        }
        st.push(c);
    }
    while (k-- > 0) st.pop();


    while (!st.empty()) {
        answer = st.top() + answer; 
        st.pop();
    }

    return answer;
}

int main() {
    vector<int>arr = { 2,4};
    vector<int>arr1 = { 3,5};
    string str = "4177252841";
    string s = solution(str,4);
    cout << s;
}