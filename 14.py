import itertools


def solution(n, weak, dist):
    m=len(weak)
    for i in range(m):
        weak.append(weak[i]+n)
    l=len(dist)
    sm=len(dist)+1
    for start in range(m):

        cu=len(dist)-1
        
        cop=1
        position=dist[cu]+weak[start]
        
        for idx in range(start,start+m):
            
            if position<weak[idx]:
                
                cop+=1
                cu-=1
                
                position=weak[idx]+dist[cu]
                
                if cop>len(dist):
                    break
        
        if sm>cop:
            sm=cop
    if sm>len(dist):        
        return -1
    return sm
print(solution(16, [1,2,3,4,5,7,8,10,11,12,14,15], [4,2,1,1]))