import sys
import heapq
input=sys.stdin.readline
n,m,st=map(int,input().split())
parent=[0]*(n+1)
for i in range(n+1):
    parent[i]=i
def find(x):

    if parent[x]!=x:
        parent[x]=find(parent[x])
    return parent[x]
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

arr=[]
for i in range(m):
    a,b,c=map(int,input().split())
    
    arr.append([c,a,b])
re=0

arr.sort()
for i in range(m):
    r,a,b=arr.pop(0)
    if find(a)==find(b):
        pass
    else:
        union(a,b)
        re=re+r

print(re)

            
