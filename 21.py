import sys
sys.setrecursionlimit(10**6)
#입력력
n,l,r=map(int,input().split())
arr=[]
for i in range(n):
    li=list(map(int,input().split()))
    arr.append(li)
dt=[[1,0],[0,1],[-1,0],[0,-1]]


#함수
def dfs(x,y,team):
    global s,c
    s+=arr[x][y]
    c+=1
    for i in metrix[x][y]:
        if vis[i[0]][i[1]]==0:
            vis[i[0]][i[1]]=team
            dfs(i[0],i[1],team)

def create(x,y):
    for i in range(4):
        dx=dt[i][0]
        dy=dt[i][1]
        if x+dx>=0 and x+dx<n and y+dy>=0 and y+dy<n:
            d=abs(arr[x][y]-arr[x+dx][y+dy])
            if d>=l and d<=r:
                metrix[x][y].append([x+dx,y+dy])

def move(x,y):
    if len(metrix[x][y])==0:
        return
    else:
        t=vis[x][y]
        

        arr[x][y]=team[t-1][0]//team[t-1][1]
#전역변수
result=0
count=1
while(count>0):
    #list
    metrix=[[[] for _ in range(n)] for _ in range(n)]
    vis=[[0]*n for _ in range(n)]
    team=[]
    #main 

    for i in range(n):
        for j in range(n):
            create(i,j)
    count=0       
    for i in range(n):
        for j in range(n):
            if vis[i][j]==0 and len(metrix[i][j])!=0:
                
                count+=1
                vis[i][j]=count
                s=0
                c=0
                dfs(i,j,count)
                team.append([s,c])


    for i in range(n):
        for j in range(n):
            if len(metrix[i][j])>0:
                move(i,j)
   
    
    result+=1
print(result-1)
