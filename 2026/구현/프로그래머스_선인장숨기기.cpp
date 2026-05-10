#include <string>
#include <vector>
#include<deque>
using namespace std;


//연속된 범위에 대한 최솟값이나 최댓값등을 구할때는 슬라이딩 윈도우를 통해 반복 횟수를 줄이자
vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {


    vector<int> answer(2);
    vector<vector<int>>board(m, vector<int>(n, 1e9));
    int nth = 0;
    for (auto drop : drops) {
        board[drop[0]][drop[1]] = nth++;
    }
    vector<vector<int>> rowMin(m, vector<int>(n - w + 1));
    //row별로 가로 슬라이딩
    for (int i = 0;i < m;i++) {
        deque<int> dq;
        for (int j = 0;j < n;j++) {
            while (!dq.empty() && dq.front() <= j - w) {
                dq.pop_front();
            }
            while (!dq.empty() && board[i][dq.back()] > board[i][j]) {
                dq.pop_back();
            }
            dq.push_back(j);
            if (j >= w - 1) {
                rowMin[i][j - w + 1] = board[i][dq.front()];
            }

        }
    }
    vector<vector<int>> Min(m, vector<int>(n - w + 1));
    //칼럼별로 세로 슬라이딩
    for (int i = 0;i < n-w+1;i++) {
        deque<int>dq;
        for (int j = 0;j < m;j++) {
            while (!dq.empty() && dq.front() <= j - h) {
                dq.pop_front();
            }
            while (!dq.empty() && rowMin[dq.back()][i] > rowMin[j][i]) {
                 dq.pop_back();
            }
            dq.push_back(j);
            if (j >= h - 1) {
                Min[j - h + 1][i] =rowMin[dq.front()][i];
            }
        }
    }
    int best = -1;
    for (int i = 0;i < m-h+1;i++) {
        for (int j = 0;j < n-w+1;j++) {
            if (Min[i][j] == 1e9) {
                return { i,j };
            }
            if (Min[i][j] > best) {
                answer[0] = i;
                answer[1] = j;
                best = Min[i][j];
            }
        }
    }

    
    

    return answer;
}
int main() {
    vector<vector<int>> arr = {
    {0, 0},
    {3, 1},
    {1, 3},
    {2, 4},
    {1, 1},
    {2, 2},
    {2, 3},
    {0, 4}
    };
    vector<int> arr1 = solution(4, 5, 2, 2, arr);
}