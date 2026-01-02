n=int(input())
arr=list(map(int,input().split()))
re=set(arr)
count=0
for i in re:
    if arr.count(i)>=i:
        count+=1
print(count)