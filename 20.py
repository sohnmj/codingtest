import itertools

n=int(input())
arr=[]
xrr=[]
trr=[]
dt=[[1,0],[0,1],[-1,0],[0,-1]]
for i in range(n):
    s=list(map(str,input().split()))
    for j in range(n):
        if s[j]=='X':
            xrr.append([i,j])
        elif s[j]=='T':
            trr.append([i,j])
    arr.append(s)

for index in itertools.combinations(xrr,3):
    jin=True    
    for id in index:
        arr[id[0]][id[1]]='O'
 
   
    for tid in trr:
        ox=tid[0]
        oy=tid[1]
        for i in range(4):
            x=ox
            y=oy
            while x<n and x>=0 and y<n and y>=0:
                
                if arr[x][y]=='S':
                    jin=False
                    break
                if arr[x][y]=='O':
                    break
                x+=dt[i][0]
                y+=dt[i][1]
            if jin==False:
                break
        if jin==False:
                break
    
    if jin ==True:
        break
    for id in index:
        arr[id[0]][id[1]]='X'

if jin ==True:
    print("YES")
else:
    print("NO")