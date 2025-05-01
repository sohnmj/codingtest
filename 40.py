import heapq
n,m=map(int,input().split())
ab=[[] for _ in range(n+1)]
for i in range(m):
    a,b=map(int,input().split())
    ab[a].append(b)
    ab[b].append(a)
inp=50000
dp=[inp] *(n+1)
q=[]
dp[1]=0
def bi_left(st,ls,target,arr):
    
    while st<=ls:
        mid=(st+ls)//2
        
        if mid==0 or (arr[mid]==target and arr[mid-1]<target):
            return mid
        elif arr[mid]<target:
            st=mid+1
        elif arr[mid]==target:
            ls=mid-1


heapq.heappush(q,[0,1])
while len(q)>0:
    d,cur=heapq.heappop(q)
    
    if d>dp[cur]:
        continue
    for des in ab[cur]:
        if dp[des]>d+1:
            dp[des]=d+1
            heapq.heappush(q,[d+1,des])

print(bi_left(1,n,dp[n],dp),dp[n],n+1-bi_left(1,n,dp[n],dp))