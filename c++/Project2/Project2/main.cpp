
/*이 문제는 이분 탐색에서 무엇을 탐색할 것인지를 정하는 것이 핵심이다.
탐색 대상은 바위를 제거한 뒤 유지할 수 있는 최소 거리이고,
판단 기준은 그 최소 거리를 만족시키기 위해 제거한 바위의 개수이다.
*/
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int binanry_serch(vector<int>rocks,int distance,int n) {
    int maximum = -1;
    int st = 0;
    int ls = distance;
    int len = rocks.size();
    while (st <= ls) {
        int mid = (st + ls) / 2;
        int re = 0;
        int pre = 0;
        int minimum = distance;
        for (int i = 1; i < len; i++) {
            int cur = rocks[i];
            if (cur - pre < mid) {
                re++;
            }
            else {
                minimum = min(minimum, cur - pre);
                pre = cur;
            }
        }
        if (re <= n) {
            maximum = max(minimum, maximum);
            st = mid + 1;
        }
        else {
            ls = mid - 1;
        }
    }
    return maximum;
}
int solution(int distance, vector<int> rocks, int n) {
    rocks.push_back(0);
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    int answer = binanry_serch(rocks,distance,n);
    return answer;
}
int main() {
    vector<int> v = {
    2, 4, 6, 8, 10
    };

    cout<<solution(12,v,4);
    

}