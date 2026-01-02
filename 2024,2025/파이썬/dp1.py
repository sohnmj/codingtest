import sys
import heapq
input=sys.stdin.readline
INF=int(1e9)
n,m,st =map(int,input().split())

arr=[[] for i in range(n+1)]
for i in range(m):
    a,b,c=map(int,input().split())
    arr[a].append((b,c))
distance=[INF]*(n+1)
vis=[0]*(n+1)

def da(sta):
    distance[sta]=0
    q=[]
    heapq.heappush(q,(0,sta))
    while(len(q)>0):
        dist,cur=heapq.heappop(q)
        if vis[cur]==1:
            cur=0
        vis[cur]=1

        if cur!=0:
            for i in range(len(arr[cur])):
                if distance[arr[cur][i][0]]>distance[cur]+arr[cur][i][1]:
                    distance[arr[cur][i][0]]=distance[cur]+arr[cur][i][1]
                    heapq.heappush(q,(distance[arr[cur][i][0]],arr[cur][i][0]))
        

da(st)
smalll=0
result=0
for i in range(1,n+1):
    print(distance[i])
for i in range(1,n+1):
    if distance[i]>smalll:
        smalll=distance[i]
    if distance[i]<INF:
        result+=1
print(result-1,smalll)            
