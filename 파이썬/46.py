n=int(input())
mapp=[]
fish=[[] for _ in range(7)]
prey=[]
dp=[[1,0],[0,1],[-1,0],[0,-1]]
def bfs(x,y,dx,dy,mapp,s):
    
    q=[[x,y,0]]
    vis=[[x,y]]
    while len(q)>0:
        
        x,y,d=q.pop(0)
        if x==dx and y==dy:
            return d
        for i in range(4):
            ax=x+dp[i][0]
            ay=y+dp[i][1]
            if ax<0 or ax>=n or ay<0 or ay>=n:
                continue
            
            if mapp[ax][ay]<=s and [ax,ay] not in vis:
                q.append([ax,ay,d+1])
                vis.append([ax,ay])
    return n**2    




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
    sm=n**2
    rx,ry=n,n
    rpt=-1
    for i in range(len(prey)):
        x,y=prey[i]
        re=bfs(sh[1],sh[2],x,y,mapp,sh[0])
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