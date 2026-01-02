n=int(input())
arr=list(map(int,input().split()))
arr.sort()
od=[]

for i in range(1,n+1):
    
    a=0
    b=len(arr)
    for j in range(len(arr)):
        if arr[j]<i:
            a+=1
        if i<arr[j]:
            b=j
            break
    print(a,b)
    if a== len(arr):
        od.append([0,i])

    
    else:
        if a==b:
            od.append([0,i])
        else:
            od.append([float((b-a)/(len(arr)-a)),i])
od.sort(key=lambda x :(-x[0],x[1]))
print(od)