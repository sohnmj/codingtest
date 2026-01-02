#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;
    sort(dist.begin(), dist.end(), greater<int>());
    cout << dist[0];
    for (int i : dist) {
        int minpos = 0;
        int min = 0;
        vector<int>minweak;
        for (int j = 0; j < n; j++) {
            int count=0;
            vector<int>weak1 = weak;
            for (int k = 0; k < i; k++) {
                int pos = (k + j) % n;
                auto it = find(weak1.begin(), weak1.end(), pos);
                if (it != weak1.end()) {
                    weak1.erase(it);
                    count++;
                }
            }
            if (min < count) {
                min = count;
                minpos = j;
                minweak = weak1;
            }
        }
        weak = minweak;
        answer++;
        if (weak.empty()) return answer;
    }

    return -1;
}
int main() {

    vector<int> weak = { 1, 5, 6, 10 };
    vector<int> dist = { 1, 2, 3, 4 };
    cout<<solution(12, weak, dist);

}