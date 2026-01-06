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
long long bs(long long st, long long ls, int n, vector<int>times) {
    if (st <= ls) {
        long long mid = (st + ls) / 2;
        //long long이 될 수 있다
        long long p = 0;
        for (int time : times) {
            p = p + (mid / time);
        }
        if (n <= p) {
            long long p1 = 0;
            for (int time : times) {
                p1 += (mid - 1) / time;
            }
            if (n <= p1) {
                return bs(st, mid - 1, n, times);
            }
            else {
                return mid;
            }
        }
        else if (n > p) {
            return bs(mid + 1, ls, n, times);
        }
    }

}
long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    answer = bs(0, (long long)times[0] * n, n, times);
    return answer;
}

int main() {
    vector<int>arr = { 40, 50, 60 };
    vector<int>arr1 = { 7,10};
    string str = "4177252841";
    int s = solution(6,arr1);
    cout << s;
}