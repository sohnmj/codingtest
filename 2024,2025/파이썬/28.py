n=int(input())
arr=list(map(int,input().split()))
def bisect(st,ls):
    while st<=ls:
        mid=(st+ls)//2
        if arr[mid]==mid:
            return mid
        elif arr[mid]>mid:
            ls=mid-1
        else:
            st=mid+1
    return -1
print (bisect(0,n-1))