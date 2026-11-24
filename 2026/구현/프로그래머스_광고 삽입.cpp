/*
[로직] 차분배열(+1/-1)→누적합으로 초별 시청자 수를 구하고, 광고 시작을 0~play-adv 전부 슬라이딩 윈도우로 확인 (최적 구간은 로그 끝에 맞춰질 수도 있어서 로그 시작만 보면 안 됨)
[문법] sprintf(buf,"%02d:%02d:%02d")로 초→HH:MM:SS 변환, 누적 시청 시간은 long long (30만×36만이면 int 범위를 넘음)
[실수] max_ad를 갱신하지 않았고 후보를 로그 시작 시각만 봐서 오답이 났음. 로그마다 adv만큼 돌아서 시간초과도 남. 범위 체크는 360000이 아니라 play 기준
[엣지] adv==play면 윈도우가 안 움직여서 00:00:00, 동점은 '>'로 가장 이른 시각 유지, 구간이 [s,e)라서 e초는 시청 시간에 미포함
*/
#include <bits/stdc++.h>
using namespace std;

int toSec(const string& s) {
    return stoi(s.substr(0,2))*3600 + stoi(s.substr(3,2))*60 + stoi(s.substr(6,2));
}
string toStr(int t) {
    char buf[9];
    sprintf(buf, "%02d:%02d:%02d", t/3600, t/60%60, t%60);
    return buf;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int play = toSec(play_time), adv = toSec(adv_time);
    vector<long long> cnt(play + 1, 0);

    for (const string& log : logs) {
        cnt[toSec(log.substr(0,8))]++;
        cnt[toSec(log.substr(9,8))]--;
    }
    for (int i = 1; i <= play; i++) cnt[i] += cnt[i-1];

    long long sum = 0;
    for (int i = 0; i < adv; i++) sum += cnt[i];
    long long best = sum;
    int bestStart = 0;

    for (int start = 1; start + adv <= play; start++) {
        sum += cnt[start + adv - 1] - cnt[start - 1];
        if (sum > best) { best = sum; bestStart = start; }
    }
    return toStr(bestStart);
}