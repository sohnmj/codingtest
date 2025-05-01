from itertools import combinations
import heapq
n=int(input())
arr=[]
x=[]
y=[]
z=[]
for i in range(n):
    inp=list(map(int,input().split()))
    
    x.append([inp[0],i])
    y.append([inp[1],i])
    z.append([inp[2],i])
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
x.sort()
y.sort()
z.sort()
ad=[]
for i in range(n-1):
    ad.append([x[i+1][0]-x[i][0],x[i+1][1],x[i][1]])
    ad.append([y[i+1][0]-y[i][0],y[i+1][1],y[i][1]])
    ad.append([z[i+1][0]-z[i][0],z[i+1][1],z[i][1]])

ad.sort()

sm=0
for dp in ad:
    if find(dp[1],vis)!=find(dp[2],vis):
        sm+=dp[0]
        union(dp[1],dp[2],vis)
print(sm)