/*
먼저 문제의 제한사항을 보면 그냥 숫자를 진수로 바꿔서 차례대로 문자열에 더해도 상관없다는 것을 알았지만 그래도 뭔가 수학적 접근으로 푸러보고 보고 싶었다.그러다 3시간을 날렸다 하하하
쉽지 않았던 문제같다. 그리고 0부터 시작하는 거로 풀었다면 더 헷갈리지 않고 잘 풀었을 것 같다. 그리고 진수를 구할때 그 수가 0이라면 예외상황이 된다는 것을 기억하자
*/
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include<set>
#include<deque>
typedef long long ll;
using namespace std;
char arr[16] = { '0','1', '2','3','4','5','6','7' ,'8' ,'9' ,'A' ,'B','C' ,'D','E','F' };
char getN(int cur, int rest, int n) {
    if (cur == 0) return '0';
    string a="";
    while (cur > 0) {
        
        a += arr[cur % n];
        cur /= n;
    }
    return a[a.length()-1-rest];
}
string solution(int n, int t, int m, int p) {
   
    string answer = "";
    for (int i = 0;i < t;i++) {
        int nth = m * i + p;
        int numberOfjarisu = n;
        int jarisu = 1;
        int cur = 0;
        int j = n;
        while (1) {
            if (nth > numberOfjarisu*jarisu) {
                
                cur += numberOfjarisu;
                nth -= numberOfjarisu*jarisu;
                numberOfjarisu = j*n-j;
                j *= n;
                jarisu++;
            }
            else {
                int next = (nth-1) / jarisu;
                int rest = (nth-1) % jarisu;
                cur += next;
                answer += getN(cur, rest, n);
                break;
            }
        }
    }
    return answer;
}
int main() {

    vector<vector<string>> relation = {
        {"100", "ryan", "music", "2"},
        {"200", "apeach", "math", "2"},
        {"300", "tube", "computer", "3"},
        {"400", "con", "computer", "4"},
        {"500", "muzi", "music", "3"},
        {"600", "apeach", "music", "2"}
    };
 cout<<solution(16,16,2,1);
}