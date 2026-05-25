    /*슬라이딩 윈도우로 풀었다.*/
    #include <iostream>
    #include <string>
    #include <vector>
    #include <deque>
    #include <algorithm>
    #include<cmath>

    using namespace std;

    vector<int> solution(vector<int> sequence, int k) {
        vector<int> answer;
        deque<int>seq;
        int sum = sequence[0];
        int st = 0;
        int end = 0;
        while(1) {
        
            if (sum < k){
                if (end + 1 >= sequence.size()) {
                    break;
                }
                sum += sequence[++end];
            }
            else if (sum > k) {
                sum -= sequence[st++];
            }
            else {
                if (answer.size() == 0 || answer[1]-answer[0] >  end-st ) {
                    answer.clear();
                    answer.push_back(st);
                    answer.push_back(end);
                }
                if (end + 1 >= sequence.size()) {
                    break;
                }
                sum += sequence[++end];
            }
        }

        return answer;
    }

int main() {
    vector<vector<int>> targets = {
        {4, 5},
        {4, 8},
        {10, 14},
        {11, 13},
        {5, 12},
        {3, 7},
        {1, 4}
    };

    vector<vector<int>> b = {
        {1, 2, 1, 2},
        {2, 1, 2, 1}
    };

    solution({ 1, 2, 3, 4, 10, 10 }, 10);
}