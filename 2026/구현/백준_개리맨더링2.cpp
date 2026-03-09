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
if문의 중요성을 깨달았다.
for문에서 모든 경우를 복잡하게 처리하려고 하기보다, 먼저 완전탐색으로 모든 경우를 탐색한 뒤
조건에 맞지 않는 케이스를 if문으로 걸러내는 방식이 훨씬 구현하기 쉬웠다.

각 선거구의 인구수는 1, 2, 3, 4 구역을 직사각형으로 계산한 뒤
그 안에 포함되는 5구역 부분을 빼는 방식으로 구했다.
하지만 이 방법은 구현 자체도 복잡하고, 정답이 틀렸을 때 디버깅하기가 매우 어려웠다.
(직접 구역을 색칠해서 확인하는 방식으로 디버깅할 수는 있다.)

대부분의 풀이는 배열에 1,2,3,4,5 구역을 직접 색칠한 뒤
각 구역의 인구를 합산하는 방식으로 해결하며, 이 방법이 구현과 디버깅 측면에서 훨씬 단순하다.
*/
int n;
int arr[20][20];
int mn = 1e9;
int p5;
int p;
int cal1(int x, int y, int d1, int d2) {
    int sum = 0;
    int sum5 = 0;
    for (int i = 0; i < x + d1; i++) {
        for (int j = 0; j <= y; j++) {
            sum += arr[i][j];
        }
    }
    for (int i = 1; i <= d1; i++) {
        for (int j = 0; j < i; j++) {
            sum5 += arr[x + i - 1][y - j];
        }
    }
    return sum - sum5;
}
int cal2(int x, int y, int d1, int d2) {
    int sum = 0;
    int sum5 = 0;
    for (int i = 0; i <= x + d2; i++) {
        for (int j = y + 1; j < n; j++) {
            sum += arr[i][j];
        }
    }
    for (int i = 1; i <= d2; i++) {
        for (int j = 0; j < i; j++) {
            sum5 += arr[x + i][y + 1 + j];
        }
    }
    return sum - sum5;
}
int cal3(int x, int y, int d1, int d2) {
        int sum = 0;
    int sum5 = 0;
    for (int i = x + d1; i < n; i++) {
        for (int j = 0; j <= y - d1 + d2 - 1; j++) {
            sum += arr[i][j];
        }
    }
    for (int i = d2; i > 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            sum5 += arr[x + d1 + d2  - i][y - d1 + d2 - 1 - j];
        }
    }
    return sum - sum5;
}
int cal4(int x, int y, int d1, int d2) {
    int sum = 0;
    int sum5 = 0;
    for (int i = x + d2 + 1; i < n; i++) {
        for (int j = y - d1 + d2; j < n; j++) {
            sum += arr[i][j];
        }
    }
    for (int i = d1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            sum5 += arr[x + d2+1 +  d1 - i][y - d1 + d2 + j];
        }
    }
    return sum - sum5;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            p += arr[i][j];
        }
    }
    
    for (int x = 0; x < n-1; x++) {
        for (int y = 0; y < n-1; y++) {
            for (int d1 = 1; d1 <= n; d1++) {
                for (int d2 = 1; d2 <= n; d2++) {
                    if (d1 + d2+x >= n) continue;
                    if (y < d1) continue;
                    if (y + d2 >= n) continue;
                    p5 = p;
                    int maximum = 0;
                    int minimum = p;

                    int p1 = cal1(x, y, d1, d2);
                    p5 -= p1;
                    if (p1 > maximum) maximum = p1;
                    if (p1 < minimum) minimum = p1;

                    int p2 = cal2(x, y, d1, d2);
                    p5 -= p2;
                    if (p2 > maximum) maximum = p2;
                    if (p2 < minimum) minimum = p2;

                    int p3 = cal3(x, y, d1, d2);
                    p5 -= p3;
                    if (p3 > maximum) maximum = p3;
                    if (p3 < minimum) minimum = p3;

                    int p4 = cal4(x, y, d1, d2);
                    p5 -= p4;
                    if (p4 > maximum) maximum = p4;
                    if (p4 < minimum) minimum = p4;

                    if (p5 > maximum) maximum = p5;
                    if (p5 < minimum) minimum = p5;

                    int d = maximum - minimum;
                    if (mn > d) {
                        mn = d;
                    }
                }
            }
        }
    }
    cout << mn;
}