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
/*이 코드는 너무 조건을 덕지덕지*/
//int solution(vector<int> people, int limit) {
//    int answer = 0;
//    sort(people.begin(), people.end());
//    int st = 0;
//    int n = people.size();
//    int ls = n - 1;
//    while (st <= ls) {
//        // 여기서도 조건 확인해주기 (st<ls)
//        while (st<ls&&people[st] + people[ls] > limit) {
//            answer++;
//            ls--;
//        }
//        ls--;
//        st++;
//        answer++;
//    }
//    return answer;
//}
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int st = 0;
    int n = people.size();
    int ls = n - 1;
    while (st <= ls) {
        if (people[st] + people[ls] <= limit) {
            st++;
        }
        ls--;
        answer++;
        
    }
    return answer;
}
int main() {
    vector<int>arr = { 40, 50, 60 };
    vector<int>arr1 = { 3,5};
    string str = "4177252841";
    int s = solution(arr,100);
    cout << s;
}