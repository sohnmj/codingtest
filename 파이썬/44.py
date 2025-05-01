from itertools import combinations
import heapq
n=int(input())
arr=[]
for i in range(n):
    inp=list(map(int,input().split()))
    inp.append(i)
    arr.append(inp)
vis=[0]*n
for i in range(n):
    vis[i]=i
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
ad=[]
c=0
for a,b in combinations(arr,2):
    d=-min(abs(a[0]-b[0]),abs(a[1]-b[1]),abs(a[2]-b[2]))
    if c==n*2:
        if ad[0][0]<d:
            heapq.heappop(ad)        
            heapq.heappush(ad,(d,a[3],b[3]))
        
        
        
    else:
        heapq.heappush(ad,(d,a[3],b[3]))
        c+=1
    
sm=0
ad.sort()
print(ad)
while(len(ad)>0):

    dp=ad.pop(-1)
    if find(dp[1],vis)!=find(dp[2],vis):
        union(dp[1],dp[2],vis)
        sm+=dp[0]
print(-sm)