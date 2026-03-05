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
이 문제는 이분 탐색 문제로, 처음에는 이분 탐색의 기준을 어떻게 잡을지가 핵심이라고 생각했다.
하지만 실제로 중요한 쟁점은 주어진 반지름으로 굴다리 전체를 비출 수 있는지를 빠르게 판별하는 방법이었다.

처음에는 방문 배열을 매번 초기화한 뒤, 각 가로등이 비추는 구간을 직접 표시하는 방식으로 구현했다.
그러나 이 방법은 매 탐색마다 O(n)의 시간이 소요되어 결국 시간 초과가 발생했다.

해설을 통해 알게 된 핵심은, 가로등의 위치가 정렬되어 있다는 점을 이용하는 것이었다.
0부터 시작하여 현재까지 비춘 최대 구간을 갱신해 나가면, 굴다리 전체를 덮을 수 있는지를 O(m) 시간 안에 판별할 수 있다.
*/
int n,m;
int arr[1000000];
int minimum=1e9;
int cango(int l) {
    int covered = 0;
    for (int i = 0; i < m; i++) {
        int p = arr[i];
        if (p - l <= covered) {
            covered = p + l;
        }
    }
    if (n <= covered) {
        return 1;
    }
    return 0;
}
void binarysearch(int st,int ls) {
    if (st <= ls) {
        int mid = (st + ls) / 2;
        int can = cango(mid);
        if (can&&mid < minimum) {
            minimum = mid;
        }
        if (can) {
            binarysearch(st, mid - 1);
        }
        else {
            binarysearch(mid + 1, ls);
        }
    }

}
int main() {

    cin >> n>>m;
    int x;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }
    binarysearch(1, n);
    cout << minimum;
    
}