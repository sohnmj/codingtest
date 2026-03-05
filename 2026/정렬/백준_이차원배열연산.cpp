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
using namespace std;


/*
정렬 문제였고 수의 등장하는 횟수를 정렬에 포함하기위해 해쉬맵을 써서 풀었다.
근데 생각해보니 숫자가 100보다 클 수 없으니 그냥 배열로 arr[101]로 횟수를 세서 풀었으면 도 좋았을 것 같다.
*/
int r,c,k;
int mr=3, mc=3;
int minimum = 0;
int mp[100][100];
bool compare(pair<int, int>a, pair<int, int>b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    else return a.second < b.second;
}
void sortR(int index) {
    unordered_map<int, int> counts;
    vector<pair<int,int>> entry;
    for (int i = 0; i < mc; i++) {
        int n = mp[index][i];
        mp[index][i] = 0;
        if (n == 0) continue;
        if (!counts.count(n)) {
            entry.push_back({ n,0 });
            counts[n] =1;
        }
        else {
            counts[n]++;
        }
    }
    for (auto& i : entry) {
        i.second = counts[i.first];
    }
    sort(entry.begin(), entry.end(),compare);
    int j = 0;
    for (auto i : entry) {
        mp[index][j++] = i.first;
        mp[index][j++] = i.second;
        if (j > 99) {
            break;
        }
    }
    if (j > mc) {
        mc = j;
    }
}
void sortC(int index) {
    unordered_map<int, int> counts;
    vector<pair<int, int>> entry;
    for (int i = 0; i < mr; i++) {
        int n = mp[i][index];
        mp[i][index] = 0;
        if (n == 0) continue;
        if (!counts.count(n)) {
            entry.push_back({ n,0 });
            counts[n] = 1;
        }
        else {
            counts[n]++;
        }
    }
    for (auto& i : entry) {
        i.second = counts[i.first];
    }
    sort(entry.begin(), entry.end(), compare);
    int j = 0;
    for (auto i : entry) {
        mp[j++][index] = i.first;
        mp[j++][index] = i.second;
        if (j > 99) {
            break;
        }
    }
    if (j > mr) {
        mr = j;
    }
}
int main() {

    cin >> r>>c>>k;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mp[i][j];
        }
    }
    r--;
    c--;
    if (mp[r][c] == k) {
        minimum = 0;
        cout << 0;
    }
    else {
        for (int i = 0; i <=100; i++) {
            if (mp[r][c] == k) {
                minimum = i;
                break;
            }
            if (mr >= mc) {
                for (int j = 0; j < mr; j++)
                    sortR(j);
            }
            else {
                for (int j = 0; j < mc; j++)
                    sortC(j);
            }
        }
        if (!minimum) {
            cout << -1;
        }
        else
             cout << minimum;
    }
        
}