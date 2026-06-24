// 예약은 시간 순서대로 예약하기 때문에 일단 시작 시간으로 정렬한뒤 우선순위 큐를 이용해 가장 빨리 끝난 종료시간을 얻는다.
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include<cmath>
#include<queue>
using namespace std;
 struct book {
    int st;
    int ls;
};
struct cmp {
    bool operator()(book a, book b) {
        return a.ls > b.ls;  
    }
};
bool s_cmp(book a, book b) {

        return a.st < b.st;

}
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    priority_queue<book,vector<book>,cmp> pq;
    vector<book>min_ls;
    for (vector<string> str : book_time) {
        int start_time = stoi(str[0].substr(0, 2)) * 60 + stoi(str[0].substr(3, 2));
        int last_time = stoi(str[1].substr(0, 2)) * 60 + stoi(str[1].substr(3, 2));
        cout << start_time<<endl;
        min_ls.push_back({ start_time,last_time });
    }
    sort(min_ls.begin(), min_ls.end(), s_cmp);
    for (book bk : min_ls) {
        bk.ls += 10;
        if (!pq.empty()) {
            int min_last=pq.top().ls;
            if (min_last <= bk.st) {
                pq.pop();
            }
        }
        pq.push(bk);
    }
    answer = pq.size();
    return answer;

}
int main() {
    vector<string> plans = {
       "SOOOL","XXXXO","OOOOO","OXXXX","OOOOE"
    };

    vector<vector<int>> b = {
        {1, 2, 1, 2},
        {2, 1, 2, 1}
    };

    cout << solution(plans);
    cout << "안영하";
}
