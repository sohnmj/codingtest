test=int(input())


for t in range(test):
    n=int(input())
    vis=[]
    li=list(map(int,input().split()))
    arr=[[0]*(n+1) for _ in range(n+1)]
    inp=[0]*(n+1)
    for i in range(n):
        inp[li[i]]=i
        for j in range(i+1,n):
            arr[li[i]][li[j]]=1
    
    m=int(input())
    
    for i in range(m):
        a,b=map(int,input().split())
        if arr[a][b]==1:
            arr[a][b]=0
            arr[b][a]=1
            inp[a]+=1
            inp[b]-=1
        else:
            arr[a][b]=1
            arr[b][a]=0
            inp[a]-=1
            inp[b]+=1
    
    for i in range(1,n+1):
        if inp[i]==0:
            vis.append(i)
    result=[]
    jin=True
    
    if len(vis)!=1:
        print("IMPOSSIBLE")
        continue
    while(len(vis)>0):
        cur=vis.pop(0)
        result.append(cur)
        
        for i in range(1,n+1):
            if arr[cur][i]==1:
                inp[i]-=1
                if inp[i]==0:
                    vis.append(i)
        
        if len(vis)!=1 and len(result)!=n:
            jin=False
            break
    if jin==True:
        for i in range(n):
            print(result[i],end=' ')
        print()
    else:
        print("IMPOSSIBLE")

