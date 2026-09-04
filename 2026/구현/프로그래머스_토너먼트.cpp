
/*
자존심 회복문제
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
int solution(int n, int a, int b)
{
    int answer = 0;
    while (1) {
        if (a % 2 == 0) {
            a /= 2;
        }
        else {
            a = a / 2 + 1;
        }
        if (b % 2 == 0) {
            b /= 2;
        }
        else {
            b = b / 2 + 1;
        }
        answer++;
        if (a == b) {
            break;
        }
    }
    cout << "Hello Cpp" << endl;

    return answer;
}
int main() {


    cout<<solution("FRANCE", "french");
}