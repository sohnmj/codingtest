
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
int dir[8][2] = { {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };
int solution(vector<int> arrows) {
    int answer = 0;
    for (int i : arrows) {

    }
    return answer;
}
int main() {
    vector<int> v = {
    2, 4, 6, 8, 10
    };

    cout<<solution(12,v,4);
    

}