from collections import deque
import sys
n,m,k,x=map(int,input().split())
arr=[[] for _ in range(n+1)]

for i in range(m):
    a, b = list(map(int, sys.stdin.readline().split()))
    arr[a].append(b)
vis=[0]*(n+1)
re=[]
que=deque()

def bfs(c,deep,vis):
    
    
    que.append(c)
    vis[c[0]]=1
    
    while len(que)!=0:
        
        c=que.popleft()
        
        if c[1]==deep+1:
            re.append(c[0])
        if c[1]==deep+2:
            break
        for ar in arr[c[0]]:
            
            if vis[ar]==0:
                que.append([ar,c[1]+1])
                vis[ar]=1
        
        

        

bfs([x,1],k,vis)
if len(re)==0:
    print(-1)
else:
    re.sort()
    for i in re:
        print(i)
