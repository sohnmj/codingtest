import heapq
t=int(input())
dt=[[1,0],[0,1],[0,-1],[-1,0]]
for i in range(t):
    n=int(input())
    arr=[]
    q=[]
    
    for j in range(n):
        arr.append(list(map(int,input().split())))
    heapq.heappush(q,[arr[0][0],0,0])
    dp=[[1000000]*n for _ in range(n)]
    while(len(q)>0):
        d,x,y=heapq.heappop(q)
        if dp[x][y]<d:
                    continue
        for ix,iy in dt:
            dx=ix+x
            dy=iy+y
            if 0<=dx and dx<n and 0<=dy and dy<n:
                
                if dp[dx][dy]>d+arr[dx][dy]:
                    dp[dx][dy]=d+arr[dx][dy]
                    heapq.heappush(q,[dp[dx][dy],dx,dy])
    for i in dp:
        print(i) 