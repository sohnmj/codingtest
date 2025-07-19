#include<iostream>
#include<vector>
using namespace std;

char aisle[6][6];
vector<pair<int, int>> Teacher;
vector<pair<int, int>> empties;
bool found = false;

int check(int n) {
    for (auto t : Teacher) {
        int x = t.second;
        int y = t.first;
        for (int i = x + 1; i < n; i++) {
            if (aisle[y][i] == 'O') break;
            if (aisle[y][i] == 'S') return 0;
        }
        for (int i = x - 1; i >= 0; i--) {
            if (aisle[y][i] == 'O') break;
            if (aisle[y][i] == 'S') return 0;
        }
        for (int i = y + 1; i < n; i++) {
            if (aisle[i][x] == 'O') break;
            if (aisle[i][x] == 'S') return 0;
        }
        for (int i = y - 1; i >= 0; i--) {
            if (aisle[i][x] == 'O') break;
            if (aisle[i][x] == 'S') return 0;
        }
    }
    return 1;
}

void dfs(int n, int d, int idx) {
    if (found) return;
    if (d == 3) {
        if (check(n)) found = true;
        return;
    }
    for (int i = idx; i < empties.size(); i++) {
        int y = empties[i].first;
        int x = empties[i].second;
        aisle[y][x] = 'O';
        dfs(n, d + 1, i + 1);
        aisle[y][x] = 'X';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> aisle[i][j];
            if (aisle[i][j] == 'T') Teacher.push_back({ i, j });
            else if (aisle[i][j] == 'X') empties.push_back({ i, j });
        }
    }
    dfs(n, 0, 0);
    cout << (found ? "YES" : "NO");
}