/*
대각선이 서로소인 직사각형을 가로지를 때, 내부의 십자 교차점을 절대 지나지 않으므로 가로 격자선과 세로 격자선을 무조건 한 번에 하나씩만 번갈아 통과하게 됩니다. 
목적지에 도달하려면 세로 방향 격자선(너비-1개)과 가로 방향 격자선(높이-1개)을 모두 지나야 합니다. 격자선을 하나 넘을 때마다 새로운 사각형 칸으로 들어가게 되므로,
이 통과하는 선의 개수들에 맨 처음 시작하는 첫 번째 칸(1개)을 더해주면 대각선이 지나가는 총 사각형의 개수는 최종적으로 'w + h - 1'이 됩니다.*/
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include<set>
typedef long long ll;
using namespace std;
int gcd(int a, int b) {
    if(a>b){
        swap(a, b);
    }
    if (b % a) {
        return gcd(b % a, a);
    }
    else {
        return a;
    }
}
long long solution(int w, int h) {
    long long answer = 1;
    int gcd1 = gcd(w, h);
    int ww = w / gcd1;
    int hh = h / gcd1;
    answer = (ll)w * (ll)h - (ww + hh - 1)*(ll)gcd1;
    return answer;
}
int main() {
    vector<int> vec = { 2,3,4 };

    std::vector<std::string> rawData = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<vector<int>> grid = {
    {1, 1, 0, 0},
    {1, 0, 0, 0},
    {1, 0, 0, 1},
    {1, 1, 1, 1}
    };
    solution(8,12);
  
}