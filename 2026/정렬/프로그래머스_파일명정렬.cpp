/*
그냥 정렬하는 문제였다.*/
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
typedef struct filecomponet{
    string head;
    int number;
    int idx;
};
bool isNumber(char c) {
    return c >= 48 && c <= 57;
}
void upper(string& head) {
    for (int i = 0;i < head.length();i++) {
        if (head[i] >= 97 && head[i] <= 122) {
            head[i] -= 32;
        }
    }
}
bool compare(filecomponet& a, filecomponet& b) {
    if (a.head == b.head) {
        if (a.number == b.number) {
            return a.idx < b.idx;
        }
        return a.number < b.number;
    }
    return a.head < b.head;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<filecomponet>arr;
    for (int i = 0;i < files.size();i++) {
        int idx = i;
        string head = "";
        int j = 0;
        while (!isNumber(files[i][j])) {
            head += files[i][j];
            j++;
        }
        upper(head);
        string numbers = "";
        while (isNumber(files[i][j])) {
            numbers += files[i][j];
            j++;
        }
        int number = stoi(numbers);
        filecomponet fc;
        fc.head = head;
        fc.idx = idx;
        fc.number = number;
        arr.push_back(fc);
        sort(arr.begin(), arr.end(), compare);
    }
    for (auto i : arr) {
        answer.push_back(files[i.idx]);
    }
    return answer;
}
int main() {

    vector<vector<string>> relation = {
        {"100", "ryan", "music", "2"},
        {"200", "apeach", "math", "2"},
        {"300", "tube", "computer", "3"},
        {"400", "con", "computer", "4"},
        {"500", "muzi", "music", "3"},
        {"600", "apeach", "music", "2"}
    };
 cout<<solution(16,16,2,1);
}