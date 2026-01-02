import heapq
n=int(input())
arr=[]
for i in range(n):

    heapq.heappush(arr,int(input()))

if n==1:
    print(arr[0])
else:
    
    sum=0
    while len(arr)>1:
        s=heapq.heappop(arr)+heapq.heappop(arr)
        sum+=s
        heapq.heappush(arr,s)
        
    
    
        
        
            
    
    print(sum)