n=int(input())
arr=list(map(int,input().split()))
oper=list(map(int,input().split()))
sm=max(arr)**n
max=max(arr)*n*-1
re=[]
def dfs(re):
    if len(re)==n-1:
        operate(re)
        
        return 0
    for i in range(4):
        if oper[i]>0:
            oper[i]-=1
            re.append(i)
            dfs(re)
            re.pop()
            oper[i]+=1
    

def operate(re):
    
    global sm
    global max
    
    result=arr[0]
    n=1
    for i in re:
        if i==0:
            result+=arr[n]
            n+=1
        if i==1:
            result-=arr[n]
            n+=1
        if i==2:
            result*=arr[n]
            n+=1
        if i==3:
            if result>=0:
                result=result//arr[n]
                n+=1
            else:
                result=(abs(result)//arr[n])*-1
                n+=1
            
                

    if sm>result:
        sm=result
    if max<result:
        max=result
dfs(re)
print(max)
print(sm)
print(1e9)