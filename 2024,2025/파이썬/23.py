from functools import cmp_to_key
n=int(input())

arr=[]
for i in range(n):
    x=list(input().split())

    arr.append([int(x[1]),int(x[2]),int(x[3]),x[0]])
def compare(a,b):
    if a[0]>b[0]:
        return -1
    elif a[0]==b[0]:
        if a[1]>b[1]:
            return 1
        elif a[1]==b[1]:
            if a[2]>b[2]:
                return -1
            elif a[2]==b[2]:
                if a[3]>b[3]:
                    return 1
                else:
                    return -1

            else:
                return 1
        else:
            return -1
    else:
        return 1
arr=sorted(arr,key=cmp_to_key(compare))


for i in range(n):
    print(arr[i][3])