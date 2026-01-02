n,m=map(int,input().split())
visited=[0]*(n+1)
count=0
for i in range(m):
    a=int(input())
    
    while a>0:
        if visited[a]==0:
            visited[a]=1
            count+=1
            break
        a-=1
print(count)
