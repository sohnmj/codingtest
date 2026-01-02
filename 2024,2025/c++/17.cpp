#include<iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string p) {
    if (p == "") {
        return "";
    }
    int right = 0;
    int left = 0;
    string answer = "";
    int len = p.length();
    int i = 0;
    do {
        if (p[i] == '(') right++;
        else left++;
        i++;
    } while (i < len && left != right);


    right = 0;
    bool jin = true;
    for (int j = 0; j < i; j++) {
        if (p[j] == '(') {
            right++;
        }
        else {
            right--;
            if (right < 0) {
                jin = false;
                break;
            }
        }
    }
    if (jin == true) {
        answer += p.substr(0, i) + solution(p.substr(i, len - i));
    }
    else {
        answer += "(";
        answer += solution(p.substr(i, len - i));
        answer += ")";
        for (int k = 1; k < i - 1; k++) {
            if (p[k] == '(') {
                answer += ")";
            }
            else {
                answer += "(";
            }
        }

    }


    return answer;
}
int main() {
    string s = "()))((()";
    std::cout << solution(s);
}