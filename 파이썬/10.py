def rotate(key):
        m=len(key)
        arr=[[0]*m for _ in range(m)]

        for i in range(m):
            for j in range(m):
                arr[j][i]=key[m-1-i][j]
        return arr
def check(arr):
    l=len(arr)//3
    jin=True
    for i in range(l,l*2):
        for j in range(l,l*2):
            if arr[i][j]!=1:
                return False
    return jin

def solution(key,lock):
    n=len(lock)
    m=len(key)  
    for i in range(4):
        key=rotate(key)
        for j in range(2*n):
            for k in range(2*n):
                ex_arr=[[0]*n*3 for _ in range(3*n)]
                for y in range(m):
                    for x in range(m):
                        ex_arr[y+j][x+k]+=key[y][x]
                for y in range(n):
                    for x in range(n):
                        ex_arr[n+y][n+x]+=lock[y][x]
                if check(ex_arr)==True:
                    return True
    return False                
     
key=[[0,0,0],[1,0,0],[0,1,1]]
rotate(key)