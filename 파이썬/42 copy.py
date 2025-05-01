n,m=map(int,input().split())
visited=[0]*(n+1)
for i in range(n+1):
    visited[i]=i
def find(x,arr):
    if arr[x]!=x:
        arr[x]=find(arr[x],arr)
    return arr[x]
count=0
for i in range(m):
    a=int(input())
    if find(a,visited)==0:
        continue
    visited[a]-=1
    count+=1
    
        
    
print(count)
