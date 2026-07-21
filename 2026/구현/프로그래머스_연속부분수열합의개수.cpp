/*힐링하고 갑니다. set이랑 unordered_set에 차이는 unordered_set은 hash map기반으로 구현되어 삽입이나 조회시 O(1)이 걸림 set은 정렬하여 저장하기 때문에 log n이 걸림. 따라서 
*/

#include <deque>
#include <algorithm>
#include<cmath>
#include<queue>
#include <unordered_map>
#include<set>
#include<iostream>
#include<unordered_set>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    unordered_set<int>ss;
    int size = elements.size();
    for (int i = 0;i < size;i++) {
        int sum = 0;
        for (int j = 0;j < size;j++) {
            int idx = (i + j) % size;
            sum += elements[idx];
            ss.insert(sum);
        }
    }
    return ss.size();
}
int main() {
    vector<vector<int>>users = { {40, 10000},{25, 10000} };
    vector<int> plans = {
7,9,1,1,4
    };

    cout<<solution(plans);
    //cout << solution(3,7);
    //cout << "안영하";
}