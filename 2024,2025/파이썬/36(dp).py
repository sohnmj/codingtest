s1=input()
s2=input()
arr=[[0]*(len(s1)+1) for _ in range(len(s2)+1)]
for i in range(len(s1)+1):
    arr[0][i]=i
for i in range(len(s2)+1):
    arr[i][0]=i
for i in range(1,len(s2)+1):
    for j in range(1,len(s1)+1):
        if s2[i-1]==s1[j-1]:
            arr[i][j]=arr[i-1][j-1]
        else:

            arr[i][j]=min(arr[i][j-1],arr[i-1][j],arr[i-1][j-1])+1
print(arr[len(s2)][len(s1)])
print(arr)