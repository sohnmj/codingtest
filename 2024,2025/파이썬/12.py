n=int(input())
answer=[[2]*(n+1) for _ in range(n+1)]
build_frame=[[1, 0, 0, 1], [1, 1, 1, 1], [2, 1, 0, 1], [2, 2, 1, 1], [5, 0, 0, 1], [5, 1, 0, 1], [4, 2, 1, 1], [3, 2, 1, 1]]
for frame in build_frame:
    x=frame[0]
    y=frame[1]
    fa=frame[2]
    op=frame[3]
    if op==0:
        if fa==0:
            if y==0:
                answer[x][y]=0
            if answer[x][y-1]==0:
                answer[x][y]=0
            if answer[x-1][y]==1:
                answer[x][y]=0
        if fa==1:
            if answer[x][y-1]==0:
                answer[x][y]=1
            if answer[x-1][y]==1 and answer[x+1][y]==1:
                answer[x][y]=1
            if answer[x+1][y-1]==0:
                answer[x][y]=1
    else:
        if fa==0:
            if answer[x][y+1]==0 and( answer[x-1][y+1]!=1):
                pass
            if answer[x-1][y+1]==1 and answer[x-1][y]!=0:
                pass
            if answer[x][y+1]==1 and answer[x+1][y]!=0:
                pass
        if fa ==1:
            if answer[x]


print(answer)            