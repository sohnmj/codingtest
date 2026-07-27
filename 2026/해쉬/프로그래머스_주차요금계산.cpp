/*이문제는 hash 맵의 활용을 이용한 문제였던 것 같다
erase() : 원소 지우기
for (const auto& pair : um) : 남아있는 원소 순회
*/
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include<cmath>
#include<queue>
#include <unordered_map>
#include<set>
#include<iostream>

using namespace std;
int calfee(int dur, vector<int>& fees) {
    int sum = fees[1];
    if (dur > fees[0]) {
        int n = (dur - fees[0]) / fees[2];
        if ((dur - fees[0]) % fees[2] != 0) {
            n++;
        }

        sum += n * fees[3];
    }
    return sum;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    set<string>list;
    unordered_map<string, int> result;
    unordered_map<string, int>um;
    for (string record : records) {
        string hour = record.substr(0, 2);
        int st;
        string minute = record.substr(3, 2);
        string number = record.substr(6, 4);

        int time = stoi(hour) * 60;
        time += stoi(minute);
        list.insert(number);

        if (record.substr(11, 2) == "IN") {
            um[number] = time;
        }
        else {
            st = um[number];
            um.erase(number);
            int dur = time - st;
            result[number] += dur;
        }

    }
    int ls = 1439;
    for (const auto& pair : um) {
        string number = pair.first;
        int st = pair.second;
        result[number] += ls - st;
    }
    for (const string& number : list) {

        int dur = result[number];
        int fee = calfee(dur, fees);
        answer.push_back(fee);
    }
    return answer;
}
int main() {
    vector<vector<int>>users = { {40, 10000},{25, 10000} };
    vector<int> plans = {
8, 6, 3, 7, 2, 5, 1, 4
    };

    cout<<solution(plans);
    //cout << solution(3,7);
    //cout << "안영하";
}