test=int(input())
def find(x,arr):
    if arr[x]!=x:

        arr[x]=find(arr[x],arr)
    return arr[x]
def union(a,b,arr):
    ad=find(a,arr)
    bd=find(b,arr)

    if ad<bd:
        arr[bd]=ad
    else:
        arr[ad]=bd
for t in range(test):
    n=int(input())
    vis=[0]*(n+1)
    for i in range(1,n+1):
        vis[i]=i
    li=list(map(int,input().split()))
    arr=[[0]*(n+1) for _ in range(n+1)]
    for i in range(n):
        for j in range(i+1,n):
            arr[li[i]][li[j]]=1
    
    m=int(input())
    for i in range(m):
        a,b=map(int,input().split())
        if arr[a][b]==1:
            arr[a][b]=0
            arr[b][a]=1
        else:
            arr[a][b]=1
            arr[b][a]=0
    rank=[]
    for i in range(1,n+1):
        count=0
        for j in range(1,n+1):
            if arr[i][j]==1:
                count+=1
        rank.append([count,i])
    rank.sort()
    jin =True
    for i in range(n-1):
        if rank[i+1][0]-rank[i][0]<1:
            jin=False
            break
    if jin ==True:
        for i in range(n):
            print(rank[n-1-i][1],end=' ')
        print()
    else:
        print("IMPOSSIBLE")