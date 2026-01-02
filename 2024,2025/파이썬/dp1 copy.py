
INF=int(1e9)
n,m =map(int,input().split())
distance=[[INF]*(n+1) for _ in range(n+1)]
for i in range(m):
    a,b=map(int,input().split())
    distance[a][b]=1
    distance[b][a]=1

x,k=map(int,input().split())
for i in range(n+1):
    distance[i][i]=0

for i in range(1,n+1):
    for j in range(1,n+1):
        for k in range(1,n+1):
            if distance[j][k]>distance[j][i]+distance[i][k]:
                distance[j][k]=distance[j][i]+distance[i][k]


            
print(distance[1][k],distance[k][x])