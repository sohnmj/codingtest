t=int(input())
for y in range(t):
    

    n,m=map(int,input().split())
    arr=[[0]*(m+2) for _ in range(n+2)]
    inp=list(map(int,input().split()))
    cu=0
    for i in range(n+2):
        for j in range(m+2):
            if i==0 or i==n+1 or j==0 or j==m+1:
                arr[i][j]=0
            else:
                arr[i][j]=inp[cu]
                cu+=1
   
    ma=0    
    dp=[[0]*(m+2) for _ in range(n+2)]
    for i in range(1,n+1):
        dp[i][1]=arr[i][1]
        if ma<dp[i][1]:
            ma=dp[i][1]
    
    
    for i in range(2,m+1):
        for j in range(1,n+1):
            dp[j][i]=max(dp[j][i-1],dp[j-1][i-1],dp[j+1][i-1])+arr[j][i]
            if ma<dp[j][i]:
                ma=dp[j][i]

    print(ma)