n=int(input())
arr=[]
dp=[0]*(n+2)
arr.append([0,0])
for i in range(n):
    a,b=map(int, input().split())
    arr.append([a,b])
giant=0
for i in range(1,n+1):
    
    cur=arr[i][0]+i-1

    if cur>n:
        continue
    mx=0
    for j in range(1,i):
       
        if mx<dp[j]:
            mx=dp[j]
    
    dp[cur]=max(dp[cur],arr[i][1]+mx)
    if giant<dp[cur]:
        giant=dp[cur]
print(giant)

        
    
