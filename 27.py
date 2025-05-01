n,x=map(int, input().split())
arr=list(map(int, input().split()))
def bisect_f(x,st,ls):
    result=-1
    while st<=ls:

        mid=((st+ls)//2)
        
        if arr[mid]==x:
            if result>mid or result==-1:
                result=mid
            ls=mid-1
        elif arr[mid]>x:
            ls=mid-1
        else:
            st=mid+1

    return result
def bisect_l(x,st,ls):
    result=-1
    while st<=ls:

        mid=((st+ls)//2)
       
        if arr[mid]==x:
            if result<mid or result==-1:
                result=mid
            st=mid+1
        elif arr[mid]>x:
            ls=mid-1
        else:
            st=mid+1

    return result
fs=bisect_f(2,0,n-1)
sc=bisect_l(2,0,n-1)

if fs!=-1 and sc!=-1:
    print(sc-fs+1)
elif fs==-1 and sc==-1:
    print(-1)
else:
    print(1)

