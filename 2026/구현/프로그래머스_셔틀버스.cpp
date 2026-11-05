/*
[로직] 마지막 버스만 보면 된다. 자리가 남으면 막차 시각, 꽉 차면 마지막 탑승자 도착 시각-1이 답
[문법] "HH:MM"을 분으로 바꿀 때 stoi(substr(0,2))*60+stoi(substr(3,2)), 출력은 sprintf(buf,"%02d:%02d",h,m)
[실수] substr(2,2)는 ':'까지 잘라 와서 stoi 예외 발생 / 루프가 break 없이 끝나면 tidx가 안 넘어가 같은 사람이 또 탐 → 태울 때마다 tidx++
[엣지] 막차에 아무도 안 타면 cur_m=0<m이라 막차 시각이 답. 같은 시각에 온 사람이 많아도 마지막 탑승자-1이면 그 사람보다 앞에 설 수 있다
*/
#include <bits/stdc++.h>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int tr=9*60;
    vector<int>stt;
    for(string tt:timetable){
        int ti=stoi(tt.substr(0,2))*60+stoi(tt.substr(3,2));
        stt.push_back(ti);
    }
    int len=timetable.size();
    sort(stt.begin(),stt.end());
    int tidx=0;
    vector<pair<int,int>>ttt;
    for(int i=0;i<n;i++){
        if(i!=0){
            tr+=t; 
        }
        int max_t=0;
        int cur_m=0;
        while(tidx<len && cur_m<m && stt[tidx]<=tr){
            cur_m++;
            max_t=tidx;
            tidx++;
        }
        ttt.push_back({cur_m,max_t});
        
    }
    int answer_t;

        auto cur=ttt.back();
        int cur_m=cur.first;
        int cli=cur.second;
        if(cur_m<m){
            answer_t=tr;
        }
        else{
            int dif=cur_m-m;
            answer_t=stt[cli-dif]-1;
        }
    
    
    char buf[6];
    sprintf(buf, "%02d:%02d", answer_t/60, answer_t%60);
    return string(buf);

}