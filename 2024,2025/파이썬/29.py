import heapq
n,m=map(int,input().split())
arr=[]
for i in range(n):
    arr.append(int(input()))
arr.sort()
start=1
end=arr[n-1]-arr[0]
gap=0
while start<=end:
    mid= (start+end)//2
    stand=arr[0]
    c=1
    for i in range(0,n):
        if arr[i]>=stand+mid:
            stand=arr[i]
            c+=1
    
    if m>c:
        end=mid-1
    elif m<c:
        start=mid+1
    else:
        
        gap=mid
        start=mid+1
    
print(gap)



