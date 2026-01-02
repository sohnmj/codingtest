n=int(input())
arr=[]

for i in range(n):
    arr.append(list(map(int,input().split())))
dp=[[0]*n for _ in range(n)]
dp[0][0]=arr[0][0]

for i in range(1,n):
    for j in range(i+1):
        if 0<j<i:
            dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+arr[i][j]
        elif j==0:
            dp[i][j]=dp[i-1][j]+arr[i][j]
        else:
            dp[i][j]=dp[i-1][j-1]+arr[i][j]
if n==1:
    print(arr[0][0])
else:
    mx=0
    for i in range(n):
        if mx<dp[n-1][i]:
            mx=dp[n-1][i]
    print(mx)


