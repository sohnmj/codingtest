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
#include <iomanip> 
using namespace std;
/*
전형적인 이분탐색문제이고
처음 st값을 잘못 정해서 처음에 틀렸다. st값이 주어진 예산에서 가장 작은 값으로 처음에 정했는데 더 작은 값이 상한액이 될 수 있는 경우를 생각 못했다.
*/
int n,total;
vector<int>demands; 
int maximum;
int getTotal(int mid) {
    int sum = 0;
    for (auto i : demands) {
        if (i > mid) {
            sum += mid;
        }
        else {
            sum += i;
        }
    }
    return sum;
}
void binary_search(int st, int ls) {
    while (st <= ls) {
        int mid = (st + ls) / 2;
        int to = getTotal(mid);
        if (total < to) {
            ls = mid - 1;
        }
        else if(total==to){
            if (maximum < mid) {
                maximum = mid;
                break;
            }
        }
        else {
            if (maximum < mid) {
                maximum = mid;
                st = mid + 1;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    long long sum=0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int demand;
        cin >> demand;
        demands.push_back(demand);
        sum += demand;
    }
    cin >> total;
    sort(demands.begin(), demands.end());
    if (total >= sum) {
        cout << demands[n - 1];
    }
    else {
        binary_search(1, demands[n - 1]);
        cout << maximum;
    }
    
}