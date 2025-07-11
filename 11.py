import sys
n=int(input())
k=int(input())
dp=[[0,1],[1,0],[0,-1],[-1,0]]
arr=[[0]*(n+2) for i in range(n+2)]
for i in range(n+2):
    arr[0][i]=2
    arr[i][0]=2
    arr[n+1][i]=2
    arr[i][n+1]=2
for i in range(k):
    a,b=map(int,input().split())
    arr[a][b]=1

l=int(input())
you=[]
for i in range(l):
    time,direct=input().split()
    you.append([int(time),direct])
#방향 인덱스
na=0
que=[]
que.append([1,1])
arr[1][1]=2
st=0

for i in range(l):

    t=you[i][0]
    de=you[i][1]
    
    for j in range(t-st):
        st+=1
        head_x=que[-1][1]+dp[na][1]
        head_y=que[-1][0]+dp[na][0]
        que.append([head_y,head_x])
        
        if arr[head_y][head_x]==2:
            print(st)
            sys.exit()
        
        if arr[head_y][head_x]==0:

            a,b=que.pop(0)
            
            arr[a][b]=0
        arr[head_y][head_x]=2
    if de=='D':
        na=(na+1)%4
    if de=='L':
        if na==0:
            na=3
        else:
            na-=1
while (True):   
    st+=1
    head_x=que[-1][1]+dp[na][1]
    head_y=que[-1][0]+dp[na][0]
    que.append([head_y,head_x])
    if arr[head_y][head_x]==0:
        a,b=que.pop(0)
        
        arr[a][b]=0
    if arr[head_y][head_x]==2:
        print(st)
        sys.exit()

            
        

            
            



