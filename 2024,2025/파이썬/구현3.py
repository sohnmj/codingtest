def solution(n):
    sn=str(n)
    re=n
    for i in range(len(sn)):
        re+=int(sn[i])
    return re
vis=[0]*(10001)

for i in range(1,10001):
    re=i
    if vis[re]==0:
        while solution(re)<10001:
            re=solution(re)
            vis[re]=1
for i in range(1,10001):
    if vis[i]==0:
        print(i)