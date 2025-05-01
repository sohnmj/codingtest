n=input()
arr=[]
l=len(n)
sum=0
curidx=0
for i in range(l):
    if ord(n[i]) >=65 and ord(n[i])<=90:
        arr.append(n[i])
        curidx+=1
    else:
        sum+=int(n[i])
arr.sort()
for i in range(len(arr)):
    print(arr[i],end="")
#만약 입력 문자열에 0이면 출력을 안해야하므로 조건문 사용
if sum!=0:
    print(sum)