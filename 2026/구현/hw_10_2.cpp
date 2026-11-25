/*
[로직] 한 칸의 물 = min(왼쪽 최고 벽, 오른쪽 최고 벽) - 그 칸 높이.
       arr[l] < arr[r]이면 오른쪽에 더 높은 벽이 확실히 있으니 l 칸의 물은 leftMax까지 참 → l 계산 후 l++
       반대면 r 칸을 rightMax 기준으로 계산 후 r-- (항상 낮은 쪽을 계산하고 안쪽으로 이동)
[문법] 투 포인터(l, r을 양 끝에서 좁혀 옴) + leftMax/rightMax를 이동하면서 갱신.
       물의 합은 int를 넘을 수 있어 long long, 테스트케이스가 많아 endl 대신 '\n'
[실수] 처음엔 왼쪽 최고 벽(stack[0])보다 높거나 같은 벽이 나올 때만 물을 계산함.
       오른쪽에 더 높은 벽이 안 나오면 계산 없이 끝나서 3 0 2 → 0 출력 (정답 2).
       물 높이는 "왼쪽 최고"가 아니라 "양쪽 중 낮은 벽"이 정한다는 걸 기억할 것
[엣지] B=0 또는 1이면 처음부터 l < r이 거짓이라 0 출력.
       오른쪽 끝 벽이 왼쪽 최고 벽보다 낮아도 rightMax 쪽 계산으로 자연스럽게 처리됨
*/
#include <iostream>
#include <vector>
using namespace std;

int maxWater(vector<int>& arr) {
    int res=0;
    int lp = 0,rp=arr.size()-1;
    int lmax=arr[lp],rmax=arr[rp];
    while(lp<rp){
        if(arr[lp]<arr[rp]){
            lmax=max(lmax,arr[lp]);
            res+=lmax-arr[lp];
            lp++;
        }
        else{
            rmax=max(rmax,arr[rp]);
            res+=rmax-arr[rp];
            rp--;
        }
    }

    return res;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test_num;
    cin >> test_num; 

    for (int t = 0; t < test_num; ++t) {
        int B;
        cin >> B; 

        vector<int> arr(B);
        for (int i = 0; i < B; ++i) {
            cin >> arr[i];
        }

        cout << maxWater(arr) << endl;
    }

    return 0;
}