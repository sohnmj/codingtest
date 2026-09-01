
/*
지워진 블럭을 삭제하는 과정에서 잘못된 풀이를 하게 되었다. 
격자판에서 블록이나 원소를 한쪽 방향으로 밀거나 떨어뜨릴 때는 반드시 이동하려는 목적지(도착 벽)에서부터 출발하여 반대 방향으로 읽어오는 투 포인터(Two Pointer) 방식을 사용해야 한다.

예를 들어 이번 문제와 같은경우 아래쪽으로 떨어뜨려야 하므로 아래쪽 부터 시작하여 빈자리를 위에서 발견한 문자로 채워 넣는 것이다.
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
bool isErase(int y, int x, vector<string> &board) {
    char sample = board[y][x];
    if (sample == '.') {
        return false;
    }
    bool jin = true;
    for (int i = 0;i < 2;i++) {
        for (int j = 0;j < 2;j++) {
            if (sample != board[i + y][j + x]) {
                return  false;
                break;
            }
        }
    }
    return jin;
}
int eraseb(int y, int x, vector<string>& board) {
    int cnt=0;
    for (int i = 0;i < 2;i++) {
        for (int j = 0;j < 2;j++) {
            if (board[y + i][x + j] != '.') {
                board[y + i][x + j] = '.';
                cnt++;
            }
        }
    }
    return cnt;
}
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<pair<int, int>>eraseblocks;
    while (1) {
        eraseblocks.clear();
        for (int i = 0;i < m-1;i++) {
            for (int j = 0;j < n-1;j++) {
                if (isErase(i, j, board)) {
                    eraseblocks.push_back({ i,j });
                }
            }
        }
        if (eraseblocks.empty()) {
            break;
        }

        for (auto eraseblock : eraseblocks) {
            int y = eraseblock.first;
            int x = eraseblock.second;
            int cnt=eraseb(y, x, board);
            answer += cnt;
        }
        for (int i = 0;i < n;i++) {
            int empty_block = m - 1;
            for (int j = m - 1;j >= 0;j--) {
                if (board[j][i] != '.') {
                    if (empty_block != j) {
                        board[empty_block][i] = board[j][i];
                        board[j][i] = '.';
                    }
                    empty_block--;
                }
            }
        }
    }
    return answer;
}
int main() {


    cout<<solution(4,5, { "CCBDE", "FFFDE", "AAABF", "CCBBF" });
}