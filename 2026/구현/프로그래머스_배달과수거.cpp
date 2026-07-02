//그리디 문제는 항상 못풀겠다. 너무 어렵다. 이문제는 가장 배달할 물건이 있거나 수거할 물건이 있는 가장 먼집을 목표로하고 가장 먼집에서 가까운 집 순으로 배달하거나 수거하는 것이 가장 최선의 방법이었다.
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include<cmath>
#include<queue>
#include <unordered_map>
using namespace std;


long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int num = deliveries.size();
    int far_dv=num-1;
    int far_pk=num-1;
    while (far_dv >= 0 || far_pk >= 0) {
        // 배달 수가 남아있는 집중에 가장 먼 집
        while (far_dv>=0) {
            if (deliveries[i]== 0) {
                far_dv--;
            }
            else {
                break;
            }
        }
        // 수거 수가 남아있는 집중에 가장 먼 집
        while (far_pk >= 0) {
            if (deliveries[i] == 0) {
                far_pk--;
            }
            else {
                break;
            }
        }
        if (far_dv == -1 && far_pk == -1) {
            break;
        }
        //그중에 가장 먼집
        long long go_far = max(far_dv, far_pk);
        answer += ((go_far + 1) * 2);
        int capacity = cap;
        //배달 먼저
        while (far_dv >= 0||capacity>0) {
            if (capacity >= deliveries[far_dv]) {
                capacity -= deliveries[far_dv];
                deliveries[far_dv] = 0;
                far_dv--;
            }
            else {
                deliveries[far_dv] -= capacity;
                capacity = 0;;
            }
        }

        //수거
        capacity = cap;
        while (far_pk >= 0 || capacity > 0) {
            if (capacity >= pickups[far_pk]) {
                capacity -= pickups[far_pk];
                pickups[far_pk] = 0;
                far_dv--;
            }
            else {
                pickups[far_pk] -= capacity;
                    capacity = 0;
            }
        }
    }
    return answer;
}
int main() {
    vector<int> plans = {
100,180,360,100,270
    };


    cout << solution(plans);
    cout << "안영하";
}
