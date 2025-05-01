n=int(input())
mapp=[]
fish=[[] for _ in range(7)]
prey=[]
dp=[[1,0],[0,1],[-1,0],[0,-1]]
def find(vis,mapp,prey):
    sm=n**2
    rx,ry=n,n
    rpt=-1
    i=0
    for cur in prey:
        x=cur[0]
        y=cur[1]
        re=vis[cur[0]][cur[1]]
    
        if sm>re:
            rx=x
            ry=y
            sm=re
            rpt=i
        elif sm==re:
            if rx>x:
                rx=x
                ry=y
                rpt=i
            elif rx==x:
                if ry>y:
                    ry=y
                    rpt=i
        i+=1
    return [sm,rx,ry,rpt]
def bfs(x,y,mapp,s,prey):
    
    q=[[x,y]]
    vis=[[n**2]*(n) for _ in range(n)]
    vis[x][y]=0
    while len(q)>0:
        
        x,y=q.pop(0)
        d=vis[x][y]
        for i in range(4):
            ax=x+dp[i][0]
            ay=y+dp[i][1]
            if ax<0 or ax>=n or ay<0 or ay>=n:
                continue
            
            if mapp[ax][ay]<=s and vis[ax][ay]==n**2:
                q.append([ax,ay])
                vis[ax][ay]=d+1
    return find(vis,mapp,prey)



for i in range(n):
    arr=list(map(int,input().split()))
    mapp.append(arr)
    for j in range(n):
        if arr[j]!=0 and arr[j]!=9:
            fish[arr[j]].append([i,j])
        if arr[j]==9:
            sh=[2,i,j,0]

for i in range(1,sh[0]):
    for j in range(len(fish[i])):
        prey.append(fish[i][j])

result=0
while len(prey)>0:
    re=bfs(sh[1],sh[2],mapp,sh[0],prey)
    sm=re[0]
    rx=re[1]
    ry=re[2]
    rpt=re[3]
    
    if sm!=n**2:
        result+=sm
        mapp[sh[1]][sh[2]]=0
        
        sh[1]=rx
        sh[2]=ry
        sh[3]+=1
        mapp[sh[1]][sh[2]]=9
        prey.pop(rpt)
        if sh[3]==sh[0]:
            sh[3]=0
            if sh[0]<7:
                for k in fish[sh[0]]:
                    prey.append(k)
            sh[0]+=1
    else:
        break
    
print(result)