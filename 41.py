n,m=map(int,input().split())
ad=[]
arr=[501]*(n+1)
for i in range(1,n+1):
    arr[i]=i
def find(x,arr):
    if arr[x]!=x:
        arr[x]=find(arr[x],arr)
    
    return arr[x]
def union(x,y,arr):
    if find(x,arr)>find(y,arr):
        arr[x]=find(y,arr)
    else:
        arr[y]=find(x,arr)
for i in range(n):
    ad.append(list(map(int,input().split())))
for i in range(n):
    for j in range(n):
        if ad[i][j]==1:
            union(i+1,j+1,arr)
plan=list(map(int,input()))
result=True
for i in range(n-1):
    if find(plan[i],arr)!=find(plan[i+1],arr):
        result=False
if result==True:
    print("YES")
else:
    print("NO")