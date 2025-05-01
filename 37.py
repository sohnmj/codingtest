n=int(input())
m=int(input())

farr=[[0]*(n+1) for _ in range(n+1)]

for i in range(m):
    a,b,c=map(int,input().split())
    if farr[a][b]!=0:
        farr[a][b]=min(farr[a][b],c)
    else:
        farr[a][b]=c
for k in range(1,n+1):
    for a in range(1,n+1):
        for b in range(1,n+1):
            if farr[a][k]==0 or farr[k][b]==0 or (a==b):
                pass
            else:
                if farr[a][b]==0:
                    farr[a][b]=farr[a][k]+farr[k][b]
                else:
                    farr[a][b]=min(farr[a][b],farr[a][k]+farr[k][b])
           
                                

for i in range(1,n+1):
    for j in range(1,1+n):
        print(farr[i][j],end=' ')
    print()
