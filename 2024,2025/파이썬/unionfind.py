n,m=map(int,input().split())

parent=[0]*(n+1)
def find(x):
    if parent[x]==0:
        return x
    else:
        parent[x]=find(parent[x])
def union(a,b):
    ap=find(a)
    bp=find(b)
    if ap==bp:
        pass
    else:
        if ap>bp:
            parent[ap]=bp
        else:
            parent[bp]=ap
for i in range(m):
    a,b=map(int,input().split())
    union(a,b)
for i in range(1,n+1):
    print(parent[i])