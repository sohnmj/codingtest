/*
이문제는 펠린드룸이 짝수인지 홀수인지 구분해서 구해야되는 문제이다. 지금의 코드는 짝수가 홀수가 나누어져 풀어져있는데 합치는 방법이 더 헷갈리지 않고 더 좋을 것 같다.
*/


#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
int solution(string s)
{
    int answer=1;
    int len=s.length();
    for(int i=0;i<len-1;i++){
        int center=i;
        int cnt=1;
        int limit=min(i,len-i-1);
        for(int j=1;j<=limit;j++){
            if(s[i+j]!=s[i-j]){
                break;
            }
            cnt+=2;
        }
        answer=max(answer,cnt);
        if(s[i]==s[i+1]){
            cnt=2;
            int limit=min(i,len-i-2);
            for(int j=1;j<=limit;j++){
                if(s[i-j]!=s[i+1+j]){
                    break;
                }
                cnt+=2;
            }
            answer=max(answer,cnt);
        }
        
    }

    return answer;
}