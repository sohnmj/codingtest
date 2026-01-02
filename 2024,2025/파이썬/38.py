n,m=map(int,input().split())
ad=[[n+1]*(n+1) for _ in range(n+1)]
for i in range(m):
    a,b=map(int,input().split())
    ad[a][b]=1
for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            ad[i][j]=min(ad[i][k]+ad[k][j],ad[i][j])
count=0
for i in range(1,n+1):
   
    c=0
    for j in range(1,n+1):
        if ad[i][j]<n+1:
            c+=1
        if ad[j][i]<n+1:
            c+=1
    if c==n-1:
        count+=1
print(count)