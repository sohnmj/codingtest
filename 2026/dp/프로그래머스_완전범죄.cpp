
/*
처음에는 그리디 문제인줄 알았는데 현재의 최선의 선택이 미래의 최선의 선택이 아닐 수 있다라는 것을 알게 되었다.
그후 브루트 포스를 하기에는 2의 40승을 계산해야되서 해결방법을 찾던와중 
배낭 문제 풀이를 알게 되었다.
B의 흔적을 무게라고 하고 A의 흔적을 가치라고 가정하고 푸는 dp문제였다.
*/
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include<queue>
using namespace std;
int bag[120];

int solution(vector<vector<int>> info, int n, int m) {
    int sum=0;
    for (auto information : info) {
        int v = information[0],w=information[1];
        sum += v;
        for (int j = m - 1;j >= w;j--) {
            bag[j] = max(bag[j], bag[j - w] + v);
        }
    }
    sum -= bag[m - 1];
    if(sum<n)return sum;
    return -1;
}
int main() {
    std::vector<std::vector<int>> vectors = { {1, 2},{2, 3},{2, 1} };

    cout<<solution(vectors,1,7);
    

}