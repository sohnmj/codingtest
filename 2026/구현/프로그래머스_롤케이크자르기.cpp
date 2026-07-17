//처음에 접근 방법이 더 좋았다. 이진탐색으로 하려니깐 계속 O(n)복잡도의 연산을 해야해서 그냥 슬라이딩 윈도우로 한번에 n복잡도로 푸는게 더 낫았다.
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include<cmath>
#include<queue>
#include <unordered_map>
#include<set>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int, int>right;
    set<int>left;
    for (int i = 0; i < topping.size();i++) {
        right[topping[i]]++;
    }
    for (int i = 0; i < topping.size();i++) {
        left.insert(topping[i]);
        right[topping[i]]--;
        if (right[topping[i]] == 0) {
            right.erase(topping[i]);
        }

        if (left.size() == right.size()) {
            answer++;
        }
        else if(left.size()>right.size()) {
            break;
        }
    }
    return answer;
}

int main() {
    vector<vector<int>>users = { {40, 10000},{25, 10000} };
    vector<int> plans = {
7000, 9000
    };

    cout << 4 % 1;
    //cout << solution(3,7);
    //cout << "안영하";
}