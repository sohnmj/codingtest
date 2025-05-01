n=int(input())
arr=[2,3,5]
dp=[2,3,5]
result=[1]
cur=0
j=0
re=[0,0,0]
for i in range(1,n):
    
    result.append(min(dp))
    for j in range(3):
        if result[i]==dp[j]:
            re[j]+=1
            dp[j]=arr[j]*result[re[j]]
            
    
    
    
   

print(result)