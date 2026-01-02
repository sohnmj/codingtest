fish_direct=[0]*17
mapp=[[] for _ in range(4)]
dx=[0,-1,-1,0,1,1,1,0,-1]
dy=[0,0,-1,-1,-1,0,1,1,1]
fish=[[] for _ in range(17)]
Max=0
#함수
def fish_move(fish,n,mapp,fish_direct):
    
    direct=fish_direct[n]

    for i in range(8):
        if i!=0:
            direct=(direct+1)%8
        
        if direct==0:
            direct=8
        fish_direct[n]=direct
        x=fish[n][0]+dx[direct]
        y=fish[n][1]+dy[direct]
        if x<0 or x>=4 or y<0 or y>=4:
            continue
        if mapp[x][y]==0:
            mapp[fish[n][0]][fish[n][1]]=0

            fish[n][0]=x
            fish[n][1]=y
            mapp[fish[n][0]][fish[n][1]]=n
            break
        if mapp[x][y]>0:
            mapp[fish[n][0]][fish[n][1]]=mapp[x][y]

            fish[mapp[x][y]][0]=fish[n][0]
            fish[mapp[x][y]][1]=fish[n][1]
            fish[n][0]=x
            fish[n][1]=y
            mapp[x][y]=n
            break
def dfs(shark,fish,mapp,fish_direct):
    global Max
   
    direct=shark[2]
    x=shark[0]
    y=shark[1]
    while (1):
        x+=dx[direct]
        y+=dy[direct]
        if x<0 or x>=4 or y<0 or y>=4:
            break
        if mapp[x][y]>0:
            mapp1 = [arr[:] for arr in mapp]
            shark1=shark[:]
            fish1= [arr[:] for arr in fish]
            fish_direct1=fish_direct[:]
            
            mapp1[shark1[0]][shark1[1]]=0
            shark1[2]=fish_direct1[mapp1[x][y]]
            
            fish_direct1[mapp1[x][y]]=-1
            shark1[3]+=mapp1[x][y]
            mapp1[x][y]=-1
            shark1[0]=x
            shark1[1]=y
            if Max<shark1[3]:
                Max=shark1[3]
            for i in range(1,17):
                if fish_direct1[i]==-1:
                    continue
                fish_move(fish1,i,mapp1,fish_direct1)
            
            dfs(shark1,fish1,mapp1,fish_direct1)

            

for i in range(4):
    arr=list(map(int,input().split()))
    for j in range(4):
        mapp[i].append(arr[2*j])
        fish[arr[2*j]].append(i)
        fish[arr[2*j]].append(j)
        fish_direct[arr[2*j]]=arr[2*j+1]
shark=[0,0,fish_direct[mapp[0][0]],mapp[0][0]]
Max=mapp[0][0]
fish_direct[mapp[0][0]]=-1
mapp[0][0]=-1




for i in range(1,17):
  
    if fish_direct[i]==-1:
        continue
    fish_move(fish,i,mapp,fish_direct)


dfs(shark,fish,mapp,fish_direct)
print(Max)


