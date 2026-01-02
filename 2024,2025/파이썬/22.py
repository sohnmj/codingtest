import sys
from collections import deque
sys.setrecursionlimit(10**9)
arr=[]
for i in range(5):
    arr.append(list(map(int,input().split())))
def solution(board):

    current=[[0,0],[0,1]]
    n=len(board)
    
    sm=bfs(current,0,n)
    return sm

#그냥 최소거리같은 문제는 bfs가 쨩인듯
def bfs(cur,time,n):
    q=[]
    q=deque()
    q.append([cur,0])
    vis= [ {(0,0), (0,1)} ]
    dt=[[1,0],[0,1],[-1,0],[0,-1]]
    result=0
    while q:
        cur,time=q.popleft()
        result=time
        
        for i in range(2):
            if cur[i][0]==n-1 and cur[i][1]==n-1:
                return result
        for d in dt:
            dx1=cur[0][0]+d[0]
            dx2=cur[1][0]+d[0]
            dy1=cur[0][1]+d[1]
            dy2=cur[1][1]+d[1]
            if 0<=dx1<n and 0<=dx2<n and 0<=dy1<n and 0<=dy2<n and arr[dx1][dy1]==0 and arr[dx2][dy2]==0:
                
                if {(dx1,dy1),(dx2,dy2)} not in vis:
                    q.append([[[dx1,dy1],[dx2,dy2]],time+1])
                    vis.append({(dx1,dy1),(dx2,dy2)})
        
        if cur[0][0]==cur[1][0]:
            dx1=cur[0][0]+1
            dx2=cur[1][0]+1
            dy1=cur[0][1]
            dy2=cur[1][1]
            if result==0:
                print(arr[dx1][dy1],arr[dx2][dy2])
            if 0<=dx1<n and 0<=dx2<n and 0<=dy1<n and 0<=dy2<n and arr[dx1][dy1]==0 and arr[dx2][dy2]==0:
                if {(cur[0][0],cur[0][1]),(cur[0][0]+1,cur[0][1])} not in vis:
                    q.append([[cur[0],[cur[0][0]+1,cur[0][1]]],time+1])
                    vis.append({(cur[0][0],cur[0][1]),(cur[0][0]+1,cur[0][1])})
                if {(cur[1][0],cur[1][1]),(cur[1][0]+1,cur[1][1])} not in vis:
                    q.append([[[cur[0][0]+1,cur[0][1]],cur[1]],time+1])
                    vis.append({(cur[1][0],cur[1][1]),(cur[0][0]+1,cur[0][1])})    
              
            dx1=cur[0][0]-1
            dx2=cur[1][0]-1
            dy1=cur[0][1]
            dy2=cur[1][1]
            if 0<=dx1<n and 0<=dx2<n and 0<=dy1<n and 0<=dy2<n and arr[dx1][dy1]==0 and arr[dx2][dy2]==0:
                
                if {(cur[0][0],cur[0][1]),(cur[0][0]-1,cur[0][1])} not in vis:
                    q.append([[cur[0],[cur[0][0]-1,cur[0][1]]],time+1])
                    vis.append({(cur[0][0],cur[0][1]),(cur[0][0]-1,cur[0][1])})
                if {(cur[1][0],cur[1][1]),(cur[1][0]-1,cur[1][1])} not in vis:
                    q.append([[[cur[0][0]-1,cur[0][1]],cur[1]],time+1])
                    vis.append({(cur[1][0],cur[1][1]),(cur[0][0]-1,cur[0][1])})    
              
        else:
            dx1=cur[0][0]
            dx2=cur[1][0]
            dy1=cur[0][1]+1
            dy2=cur[1][1]+1
            if 0<=dx1<n and 0<=dx2<n and 0<=dy1<n and 0<=dy2<n and arr[dx1][dy1]==0 and arr[dx2][dy2]==0:
                
                    if {(cur[0][0],cur[0][1]),(cur[0][0],cur[0][1]+1)} not in vis:
                        q.append([[cur[0],[cur[0][0],cur[0][1]+1]],time+1])
                        vis.append({(cur[0][0],cur[0][1]),(cur[0][0],cur[0][1]+1)})
                    if {(cur[1][0],cur[1][1]),(cur[1][0],cur[1][1]+1)} not in vis:
                        q.append([[[cur[1][0],cur[1][1]+1],cur[1]],time+1])
                        vis.append({(cur[1][0],cur[1][1]),(cur[1][0],cur[1][1]+1)})
            dx1=cur[0][0]
            dx2=cur[1][0]
            dy1=cur[0][1]-1
            dy2=cur[1][1]-1
            if 0<=dx1<n and 0<=dx2<n and 0<=dy1<n and 0<=dy2<n and arr[dx1][dy1]==0 and arr[dx2][dy2]==0:
                
                    if {(cur[0][0],cur[0][1]),(cur[0][0],cur[0][1]-1)} not in vis:
                        q.append([[cur[0],[cur[0][0],cur[0][1]-1]],time+1])
                        vis.append({(cur[0][0],cur[0][1]),(cur[0][0],cur[0][1]-1)})
                    if {(cur[1][0],cur[1][1]),(cur[1][0],cur[1][1]-1)} not in vis:
                        q.append([[[cur[1][0],cur[1][1]-1],cur[1]],time+1])
                        vis.append({(cur[1][0],cur[1][1]),(cur[1][0],cur[1][1]-1)})

                
                


                
        
        
    return result-1
    
print(solution(arr))