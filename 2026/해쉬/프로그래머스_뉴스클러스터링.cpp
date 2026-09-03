
/*
그냥 두개의 알파벳 조합을 1~26*26까지의 수로 치환하여 unordered_map을 사용하지 않고 배열로만 사용하는 방식도 있지만 알파뱃 조합의
원소개수가 많아지면 수로 치환해야하는 범위가 매우 넓어지므로 나중에 교집합이나 합집합을 계산하기 위한
시간도 커질 것이어서 그냥 unordered_map으로 푸는 풀이가 더 범용성이 넓은 풀이인것 같다.
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
bool isCharacter(char c) {
    return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}
string formedCharacter(string str) {
    string result = "";
    for (int i = 0;i < 2;i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            result += str[i] + 32;
        }
        else {
            result += str[i];
        }
    }
    return result;
}
int solution(string str1, string str2) {
    unordered_map<string, int>str1m, str2m;
    int unioncnt = 0;
    int intercnt = 0;
    int answer = 0;
    for (int i = 0;i < str1.length() - 1;i++) {
        string sub = str1.substr(i, 2);
        if (!isCharacter(sub[0]) || !isCharacter(sub[1])) continue;
        sub = formedCharacter(sub);
        str1m[sub]++;
        unioncnt++;
    }
    for (int i = 0;i < str2.length() - 1;i++) {
        string sub = str2.substr(i, 2);
        if (!isCharacter(sub[0]) || !isCharacter(sub[1])) continue;
        sub = formedCharacter(sub);
        str2m[sub]++;
        unioncnt++;
    }
    
    for (auto m : str1m) {
        string word = m.first;
        int cnt = m.second;
        if (str2m.count(word)) {
            int mincnt = min(cnt, str2m[word]);
            intercnt += mincnt;
        }
    }
    if (unioncnt == 0) {
        return 1 * 65536;
    }
    unioncnt -= intercnt;
    return (int)((double)intercnt/unioncnt*65536);
}
int main() {


    cout<<solution("FRANCE", "french");
}