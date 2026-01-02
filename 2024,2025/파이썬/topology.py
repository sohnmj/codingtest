from collections import deque
n,m=map(int,input().split())
arr=[[] for _ in range(n+1)]
indegree=[0] *(n+1)
for i in range(m):
    a,b=map(int,input().split())
    arr[a].append(b)
    indegree[b]+=1
def topology():
    q=deque()
    for i in range(1,n+1):
        if indegree[i]==0:
            q.append(i)
    while q:
        now=q.popleft()
        print(now)
        for i in range(len(arr[now])):
            indegree[arr[now][i]]-=1
            if indegree[arr[now][i]]==0:
                q.append(arr[now][i])
topology()