n,m,k=map(int,input().split())

mapp=[]
sharks=[[] for _ in range(m+1)]
sdirect=[[]for _ in range(m+1)]
dp=[[-1,0],[1,0],[0,-1],[0,1]]
smell=[[[0,0]for _ in range(n)] for _ in range(n)]

ssum=m
def smell_pl(i,k,smell,sharks):
    x,y,t=sharks[i]
    if sharks[i][0]<20:
        
        smell[x][y][0]=i
        smell[x][y][1]=k
        mapp[x][y]=i
def move(mapp,sharks,n,sdirect,dp,smell,k,t):
    global ssum
    if sharks[n][0]!=20:
        jin=False
        for i in sdirect[n][sharks[n][2]]:
            
                
            
            x=sharks[n][0]+dp[i][0]
            y=sharks[n][1]+dp[i][1]
            
            if x<0 or x>=len(mapp) or y<0 or y>=len(mapp):
                continue
            if mapp[x][y]==0:
                
                
                    
                mapp[x][y]=n
                sharks[n][0]=x
                sharks[n][1]=y
                sharks[n][2]=i
                jin=True
                break
            
            elif mapp[x][y]<n:
                
                
                if smell[x][y][0]==0:
                
                    
                    if sharks[mapp[x][y]][0]==x and sharks[mapp[x][y]][1]==y:
                        
                        
                    
                        sharks[n][0]=20
                        ssum-=1
                        jin=True
                        break
                    
        
        if jin ==False:
            for i in sdirect[n][sharks[n][2]]:
                
                x=sharks[n][0]+dp[i][0]
                y=sharks[n][1]+dp[i][1]
                
                if x<0 or x>=len(mapp) or y<0 or y>=len(mapp):
                    continue
                
                if mapp[x][y]==n:
                    
                    sharks[n][0]=x
                    sharks[n][1]=y
                    sharks[n][2]=i
                    
                    break
        
   
    
            

for i in range(n):
    mapp.append(list(map(int,input().split())))
    for j in range(n):
        if mapp[i][j]>0:
            sharks[mapp[i][j]].append(i)
            sharks[mapp[i][j]].append(j)
arr=list(map(int,input().split()))
for i in range(m):
    sharks[i+1].append(arr[i]-1)
    
for i in range(m):
    for j in range(4):
        sdirect[i+1].append(list(map(int,input().split())))
        for kk in range(4):
            sdirect[i+1][j][kk]-=1
t=1
while(t<=1000):
    for i in range(1,m+1):
        smell_pl(i,k,smell,sharks)
    for i in range(1,m+1):
        move(mapp,sharks,i,sdirect,dp,smell,k,t)
    
    for i in range(n):
        for j in range(n):
            if smell[i][j][0]>0:
                smell[i][j][1]-=1
                if smell[i][j][1]==0:
                    smell[i][j][0]=0
                    mapp[i][j]=0
            
    
    t+=1
    if ssum==1:
        break
    

if ssum==1:
    print(t-1)
else:
    print(-1)
