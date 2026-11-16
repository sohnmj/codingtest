/*
[로직] 삭제한 행의 prev/next를 지우지 않고 남겨둠 → Z는 LIFO라 복구할 때 이웃이 반드시 살아 있어 링크 2개만 되돌리면 끝(O(1))
[문법] 배열로 만든 연결리스트 prev/next + 양 끝 표시값 -1/n, string answer(n,'O')로 미리 채우고 C에서 X만 찍기 (마지막 조립 불필요)
[실수] 첫 풀이에서 vector erase/insert(O(n)) 써서 시간초과, U/D 방향 반대, stoi(cmd[2])는 char라 불가(substr로 두 자리 수까지), Z에서 pop_back 누락
[엣지] 마지막 행 삭제 시 cur는 위로 이동 + next[cur]=n으로 끝 재설정. 행이 하나만 남은 상태의 C는 문제에서 안 나온다고 보장
*/
#include <bits/stdc++.h>
#include<string>

using namespace std;

string solution(int n, int k, vector<string> cmds) {
    string answer (n,'O');
    vector<int>arr;
    vector<int>prev,next;
    for(int i=0;i<n;i++){
        prev.push_back(i-1);
        next.push_back(i+1);
    }
    vector<int>del;
    int cur_idx=k;
    for(string cmd:cmds){
        if(cmd[0]=='U'){
            int di=stoi(cmd.substr(2));
            while(di--){
                cur_idx=prev[cur_idx];
            }
        }
        else if(cmd[0]=='C'){
            int next_idx=next[cur_idx];
            if(next_idx==n){
                del.push_back(cur_idx);
                answer[cur_idx]='X';
                cur_idx=prev[cur_idx];
                next[cur_idx]=n;
            }
            else{
                del.push_back(cur_idx);
                answer[cur_idx]='X';
                if(prev[cur_idx]!=-1){
                    next[prev[cur_idx]]=next[cur_idx];
                }
                if(next[cur_idx]!=n) {
                    prev[next[cur_idx]]=prev[cur_idx];
                    cur_idx=next[cur_idx];
                }

            }
            
        }
        else if(cmd[0]=='Z'){
            int del_idx=del.back();
            del.pop_back();
            answer[del_idx]='O';
            if(prev[del_idx]!=-1){
                next[prev[del_idx]]=del_idx;
            }
            if(next[del_idx]!=n){
                prev[next[del_idx]]=del_idx;
            }
        }
        else if(cmd[0]=='D'){
            int di=stoi(cmd.substr(2));
            while(di--){
                cur_idx=next[cur_idx];
            }
        }
        else continue;
    }

    return answer;
}