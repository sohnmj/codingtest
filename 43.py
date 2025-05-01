n,m=map(int,input().split())
arr=[]
parent=[0] *n
for i in range(n):
    parent[i]=i
def find(x,arr):
    if arr[x]!=x:
        arr[x]=find(arr[x],arr)
    
    return arr[x]
def union(a,b,arr):
    if find(a,arr)!=find(b,arr):
        if find(a,arr)<find(b,arr):
            arr[find(b,arr)]=find(a,arr)
        else:
            arr[find(a,arr)]=find(b,arr)
    

for i in range(m):
    a,b,d=map(int,input().split())
    arr.append([d,a,b])
arr.sort()
print (arr)
sm=0
for i in range(m):
    d,a,b=arr.pop(0)
    print(find(a,parent),find(b,parent))
    if find(a,parent)==find(b,parent):
        sm+=d
    else:
        union(a,b,parent)
    
print(sm)