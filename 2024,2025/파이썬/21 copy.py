from collections import deque
#입력력

n,l,r=map(int,input().split())
arr=[]
for i in range(n):
    li=list(map(int,input().split()))
    arr.append(li)
dt=[[1,0],[0,1],[-1,0],[0,-1]]


#함수
def bfs(x,y):
    nei=deque()
    union[x][y]=1
    nei.append([x,y])
    team=[]
    while nei:
        cur=nei.popleft()
        team.append(cur)
        x=cur[0]
        y=cur[1]
        for i in range(4):
            dx=dt[i][0]
            dy=dt[i][1]
            if x+dx>=0 and x+dx<n and y+dy>=0 and y+dy<n and union[x+dx][y+dy]==0:
                d=abs(arr[x][y]-arr[x+dx][y+dy])
                if d>=l and d<=r:
                    nei.append([x+dx,y+dy])
                    union[x+dx][y+dy]=1
    sum=0
    print(team)
    for i in team:
        sum+=arr[i[0]][i[1]]
    for i in team:
        arr[i[0]][i[1]]=sum//len(team)
    return len(team)


#전역변수
result=0
count=1
while(count>0):
    count=0
    #main 
    union=[[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if union[i][j]==0:
                bf=bfs(i,j)
                
                if bf>1:
                    count=1
        
            
    
    result+=1
print(result-1)
