import copy
import itertools
n, m=map(int,input().split())
arr=[]
one=[]
virus=[]
max=0
df=[[-1,0],[0,-1],[1,0],[0,1]]
def counti(brr):
    re=0
    for i in range(n):
        for j in range(m):
            if brr[i][j]==0:
                re+=1
    return re


def spray(id,brr):
    
    for i in range(4):
        x=id[0]+df[i][0]
        y=id[1]+df[i][1]
        if x<0 or x>=n or y<0 or y>=m:
            continue
        if brr[x][y]==0:
            brr[x][y]=2
            spray([x,y],brr)


for i in range(n):
    a=list(map(int,input().split()))
    for j in range(len(a)):
        if a[j]==0:
            one.append([i,j])
        elif a[j]==2:
            virus.append([i,j])
    arr.append(a)

for i,j,k in  itertools.combinations(one,3):
    brr=copy.deepcopy(arr)
    brr[i[0]][i[1]]=1
    brr[j[0]][j[1]]=1
    brr[k[0]][k[1]]=1
    for t in virus:
        spray(t,brr)
        
    cu=counti(brr)
    if max<cu:
        max=cu

print(max)            

            
            
            
            
            
                
