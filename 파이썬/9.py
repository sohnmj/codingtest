def solution(s):
    l=len(s)
    sm=l
    for i in range(1,1+l):
        c=1
        t=0
        pre=s[0:i]
        j=i+i
        print(i)
        print()
        while(j<=l):
            if s[j-i:j]==pre:
                c+=1
            else:
                if c!=1:
                    co=1
                    while c>=10:
                        c=c//10
                        co+=1
                
                    t+=i+co
                    c=1
                    
                else:
                    t+=i
            pre=s[j-i:j]
            j=j+i  
            print(c,t)
        if c==1:
            t+=i
        else:
            co=1
            while c>=10:
                c=c//10
                co+=1
            t+=i+co
        
        if j<l+i:
            j-=i
            t+=l-j
        print (c,t)
        if sm>t:
            sm=t
                         
        
            
    answer = sm
    return answer
n=input()
print(solution(n))