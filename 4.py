n=int(input())
arr=list(map(int,input().split()))
l=len(arr)
hap=sum(arr)
arr.sort()
for i in range(1,hap+1):
    h=i
    
    for j in range(l):
        if h-arr[l-1-j]>=0:
            h=h-arr[l-1-j]
    if h>0:
        print(i)
        