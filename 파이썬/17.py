import sys
from collections import deque
df=[[-1,0],[0,1],[1,0],[0,-1]]
n,k =map(int,input().split())
arr=[]
que=[]
for i in range(n):
    a= list(map(int, sys.stdin.readline().split()))
    for j in range(n):
        if a[j]>0:
            que.append([a[j],i,j])
    arr.append(a)
s,xe,ye =map(int,input().split())

    
que=sorted(que)


time=0
pre=0
while len(que)!=0:
    
    cu=que.pop(0)
    
    if pre>cu[0] or (len(que)==0):
        time+=1
    if time==s:
        break
    for i in df:
        x=cu[1]+i[0]
        y=cu[2]+i[1]
        if x<0 or x>=n or y<0 or y>=n:
            continue
        if arr[x][y]==0:
            arr[x][y]=cu[0]
            que.append([cu[0],x,y])
    
    pre=cu[0]
print(arr[xe-1][ye-1])