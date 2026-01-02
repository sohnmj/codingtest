#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int** vis;
int* sets;
void inmaze(char** maze, int n, int m) {

    for (int i = 0; i < 2 * n + 1; i++) {
        for (int j = 0; j < 2 * m + 1; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    maze[i][j] = '+';
                }
                else {
                    maze[i][j] = '-';
                }

            }
            else {
                if (j % 2 == 0) {
                    maze[i][j] = '|';
                }
                else {
                    maze[i][j] = ' ';
                }
            }

        }
    }
}
int find(int x) {
    if (sets[x] == x) {
        return x;
    }
    return sets[x]=find(sets[x]);
}
void unionset(int y, int x) {
    int a = find(vis[y][x]);
    int b = find(vis[y][x+1]);
    if (a < b) {
        sets[b] = a;
    }
    else {
        sets[a] = b;
    }

}
int main(void) {

    srand((unsigned int)time(NULL));
    int m, n;
    cin >> m >> n;
    vis = new int* [n];
    for (int i = 0; i < n; i++) {
        vis[i] = new int[m];
        for (int j = 0; j < m; j++) {
            vis[i][j] = 0;
        }
    }
    char** maze = new char* [n * 2 + 1];
    for (int i = 0; i < n * 2 + 1; i++) {
        maze[i] = new char[2 * m + 1];
    }

    inmaze(maze, n, m);
    
    
    sets = new int[n * m+1];
    for (int i = 1; i <= n * m; i++) {
        sets[i] = i;
    }
    sets[0] = 0;
    int set = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == 0) {
                vis[i][j] = set++;
            }
        }
        if (i != n - 1) {
            
            for (int j = 0; j < m - 1; j++) {
                int rm = rand() % 2;
                if (rm == 1&& find(vis[i][j + 1]) != find(vis[i][j])) {
                    unionset(i, j);
                    maze[2 * i + 1][2 * j + 2] = ' ';
                }
                
            }
            for (int j = 0; j < m; j++) {
                vis[i][j] = find(vis[i][j]);
            }
            int p;
            int start = 0;
            int last = 0;
            p = find(vis[i][0]);
            for (int j = 1; j < m; j++) {
                if (find(vis[i][j]) == p) {
                    last = j;
                }
                else {
                    int rmj =start+ rand() % (last - start + 1);
                    vis[i + 1][rmj] = find(vis[i][rmj]);
                    maze[2 * i + 2][2 * rmj + 1] = ' ';
                    start = j;
                    last = j;
                }
            }
            int rmj = start+rand() % (last -start + 1);
            vis[i + 1][rmj] = find(vis[i][rmj]);
            maze[2 * i + 2][2 * rmj + 1] = ' ';
            
            
            for (int j = 0; j < m ; j++) {
                int rm;
                if (find(vis[i][j])!=find(vis[i+1][j])) {
                    rm = rand() % 2;
                    if (rm == 1) {
                        vis[i + 1][j] = vis[i][j];
                        maze[2 * i + 2][2 * j + 1] = ' ';
                    }
                }
            }
        }
        else {
            for (int j = 0; j < m-1; j++) {
                if (find(vis[i][j]) !=find(vis[i][j+1])) {
                   unionset(i,j);
                   maze[2 * i +1][2 * j + 2] = ' ';
                }
            }
        }
    }

    FILE* fo;
    fo = fopen("output.maz","w");
    for (int i = 0; i < 2 * n + 1; i++) {
        for (int j = 0; j < 2 * m + 1; j++) {
            fprintf(fo,"%c",maze[i][j]);
        }
        fprintf(fo, "\n");
    }
}