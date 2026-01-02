from itertools import combinations
def find_d(ch_d):
    result=0
    for i in range(n):
        for j in range(n):
            sm=0
            if arr[i][j]==1:
                sm=2*n
                for ch in ch_d:
                    if abs(i-chicken[ch][0])+abs(j-chicken[ch][1])<sm:
                        sm=abs(i-chicken[ch][0])+abs(j-chicken[ch][1])
            result+=sm        
    return result



n,m=map(int,input().split())
arr=[[0]*n for _ in range(n)]
chicken=[]
for i in range(n):
    li=list(map(int,input().split()))
    for j in range(n):
        arr[i][j]=li[j]
        if li[j]==2:
            chicken.append([i,j])
arr1=[]
for i in range(len(chicken)):
    arr1.append(i)
sma=10000000000
for ch in list(combinations(arr1,m)):
    
    case=find_d(ch)
    if sma>case:
        sma=case
print (sma)
